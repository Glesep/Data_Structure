#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
using namespace std;

const string OPERATORS = "+-*/()";
const int PRECEDENCE[] = {1, 1, 2, 2, -1, -1}; // 2번 규칙을 예외처리하지 않기 위해
stack<char> operator_stack;

string::size_type is_operator(char ch)
{
    return OPERATORS.find(ch);
}

void process_op(char op, stringstream &postfix)
{
    if (operator_stack.empty() || op == '(')
    {
        operator_stack.push(op);
    }
    else
    {
        char top_op = operator_stack.top();
        if (precedence(op) > precedence(top_op))    // 2번 규칙과 닫는 괄호를 처리함 머리로 생각해보기
        {
            operator_stack.push(op);
        }
        else
        {
            while (!operator_stack.empty() && precedence(op) <= precedence(top_op))
            {
                operator_stack.pop();
                if (top_op == '(')      // op는 닫는괄호임을 내포
                    break;
                postfix << top_op << ' ';
                if (!operator_stack.empty())
                    top_op = operator_stack.top();
            }
            if (op != ')')              // 닫는 괄호는 push X
                operator_stack.push(op);
        }
    }
}

int precedence(char op)
{
    return PRECEDENCE[is_operator(op)];
}

string convert(string infix)
{
    stringstream postfix, infixstream(infix);
    string token;
    while (getline(infixstream, token, ' '))
    {
        if (isdigit(token[0]))
        {
            postfix << token << ' ';
        }
        else if (is_operator(token[0]) != string::npos)
        { // operator
            process_op(token[0], postfix);
        }
        else
        {
            throw runtime_error("Syntax Error: invalid character encountered.");
        }
    }
    while (!operator_stack.empty())
    {
        char op = operator_stack.top();
        if (op == '(')
            throw runtime_error("Unmatched parenthesis.");
        postfix << op << ' ';
        operator_stack.pop();
    }
    return postfix.str();
}

int main()
{
    string expr;
    cout << "Enter an infix expression: ";
    getline(cin, expr);
    cout << convert(expr) << endl;
    return 0;
}