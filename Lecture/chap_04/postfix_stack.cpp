#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>
using namespace std;

const string OPERATORS = "+-*/";
stack<int> operand_stack;

// 문자 ch가 연산자인지 검사
string::size_type is_operator(char ch)
{
    return OPERATORS.find(ch);
}

int eval_op(char op)
{
    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    int rhs = operand_stack.top();  // 오른쪽 피연산자로 저장
    operand_stack.pop();

    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    int lhs = operand_stack.top();  // 왼쪽 피연산자로 저장
    operand_stack.pop();

    int result = 0;

    switch (op)
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
    }
    return result;
}

int eval(string expr)
{
    stringstream exprstream(expr);
    string token;

    while (getline(exprstream, token, ' '))
    {
        if (isdigit(token[0])) // 피연산자 (음수는 표현 못함)
        {
            operand_stack.push(stoi(token));
        }

        else if (is_operator(token[0]) != string::npos)
        {
            int result = eval_op(token[0]); // 연산자
            operand_stack.push(result);
        }

        else
        {
            throw runtime_error("Syntax Error: invalid character encountered.");
        }
    }

    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    int answer = operand_stack.top();
    operand_stack.pop();

    if (operand_stack.empty())
        return answer;

    else
    {
        throw runtime_error("Syntax Error: Stack should be empty.");
    }
}

int main()
{
    string expr;
    cout << "Enter a postfix expression: ";
    getline(cin, expr);
    try
    {
        cout << eval(expr) << endl;
    }

    catch (exception &e)        // 모든 종류의 에러
    {
        cout << e.what() << endl;
    }
    return 0;
}