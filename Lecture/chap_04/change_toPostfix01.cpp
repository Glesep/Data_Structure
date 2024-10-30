#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
using namespace std;

const string OPERATORS = "+-*/";
const int PRECEDENCE[] = {1, 1, 2, 2};

stack<char> operator_stack;

string::size_type is_operator(char ch)
{
    return OPERATORS.find(ch);
}

// 우선순위 파악하는 함수
int precedence(char op)
{
    return PRECEDENCE[is_operator(op)];
}

void process_op(char op, stringstream &postfix)
{
    if (operator_stack.empty())
    {
        operator_stack.push(op);
    }
    else
    {
        char top_op = operator_stack.top();
        // 우선순위가 나보다 top이 작다면
        if (precedence(op) > precedence(top_op))
        {
            operator_stack.push(op);
        }
        else
        {
            // 우선순위가 나보다 top이 높거나 같다면 (같은 경우는 먼저 나온 연산자가 우선순위가 높다)
            while (!operator_stack.empty() && precedence(op) <= precedence(top_op))
            {
                operator_stack.pop();
                /* discard since it’s top_op */
                postfix << top_op << ' ';
                if (!operator_stack.empty())
                    top_op = operator_stack.top();
            }
            operator_stack.push(op);
        }
    }
}

string convert(string infix)
{
    stringstream postfix, infixstream(infix);
    string token;
    while (getline(infixstream, token, ' ')) // 모든 연산자와 피연산자가 한 칸의 공백문자로 구분되어 있다고 가정
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
        postfix << op << ' ';
        operator_stack.pop();
    }
    
    return postfix.str();
}

int main()
{
    string expr;
    getline(cin, expr);
    cout << convert(expr) << endl;
    return 0;
}