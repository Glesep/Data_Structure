#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>
using namespace std;

const string OPERATORS = "+-*/()";
const int PRECEDENCE[] = {1, 1, 2, 2, -1, -1}; // 2번 규칙을 예외처리하지 않기 위해

stack<char> operator_stack;     // 연산자 저장 스택
stack<double> operand_stack;       // 피연산자 저장 스택

string::size_type is_operator(char ch)
{
    return OPERATORS.find(ch);
}

/**
 * @brief 후위표기식 계산 함수
 * 
 * @param op 계산에 이용할 연산자
 * @return double 결과 값
 */
double eval_op(char op)
{
    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    double rhs = operand_stack.top();  // 오른쪽 피연산자로 저장
    operand_stack.pop();

    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    double lhs = operand_stack.top();  // 왼쪽 피연산자로 저장
    operand_stack.pop();

    double result = 0;

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

int precedence(char op)
{
    return PRECEDENCE[is_operator(op)];
}

/**
 * @brief 연산자 간 우선순위를 고려하여 진행하는 함수
 * 
 * @param op 현재 operator
 */
void process_op(char op)
{
    if (operator_stack.empty() || op == '(')
    {
        operator_stack.push(op);
    }
    else
    {
        char top_op = operator_stack.top();
        if (precedence(op) > precedence(top_op))    // 위에서 op가 여는 괄호일 때, 여는 괄호는 -1이므로 닫는 괄호를 제외한 모든 operator는 push됨(2번 규칙과 닫는 괄호를 처리함)
        {
            operator_stack.push(op);
        }
        else
        {   
            // top_op가 op보다 우선순위가 높거나 같을 때(우선순위가 같을 때는 먼저 들어간 쪽이 우선순위가 높으므로 포함)
            while (!operator_stack.empty() && precedence(op) <= precedence(top_op))
            {
                operator_stack.pop();
                if (top_op == '(')      // op는 닫는괄호임을 내포 (-1보다 작거나 같은 건 닫는괄호 (-1) 밖에 없음)
                    break;

                double result = eval_op(top_op);      // top_op로 eval_op 호출
                operand_stack.push(result);           // 결과를 operand_stack에 저장

                
                if (!operator_stack.empty())
                    top_op = operator_stack.top();
            }
            // op가 우선순위가 높을 때
            if (op != ')')              // 닫는 괄호는 push X
                operator_stack.push(op);
        }
    }
}

/**
 * @brief 후위표기식으로 변환과 동시에 계산하는 함수
 * 
 * @param infix 중위표기식
 * @return double 계산 결과
 */
double convertAndCalculate(string infix)
{
    
    string operandToken;    // operand를 구하기 위해 정의
    bool prevIsOperator = false;    // 이전이 Operator라면 true ( ')' 제외 )
    bool isNegative = false;        // operand가 음수라면 true

    for (int i = 0; i < infix.length(); i++)
    {
        // cout << infix[i] << endl;       // debug

        // operand가 실수일 수 있으므로 '.'도 operandToken에 포함
        if (isdigit(infix[i]) || infix[i] == '.') {
            operandToken += infix[i];
            prevIsOperator = false;
        }

        // is_operator에 해당하면
        else if (is_operator(infix[i]) != string::npos) {
            // 1. 음수 표현인 경우
            if (infix[i] == '-'  && infix[i-1] != ')' && (prevIsOperator || i == 0)) {
                if (!isNegative) {
                    operandToken += infix[i];
                    isNegative = true;
                }

                // 연산자가 연달아 나오면 오류
                else {
                    throw runtime_error ("Operator Error");
                }
            }

            // 2. 나머지 경우, 피연산자, 연산자 스택에 넣은 후 process_op 함수 호출
            else if (!prevIsOperator || infix[i] == '(' || infix[i] == ')') {
                isNegative = false;
                if (infix[i] != ')') {
                    prevIsOperator = true;
                }
                else
                    prevIsOperator = false;

                if (operandToken != "") {
                    operand_stack.push(stod(operandToken));
                    operandToken = "";
                }

                process_op(infix[i]);

            }

            // 연산자가 연달아 나오면 오류
            else {
                throw runtime_error ("Operator Error");
            }
        }

        else
        {
            throw runtime_error("Syntax Error: invalid character encountered.");
        }
    }

    // 뒤에 남은 수들이 있다면 operand_stack에 push
    if (operandToken != "")
        operand_stack.push(stod(operandToken));

    // 남은 연산자가 없을 때까지 계산 반복
    while (!operator_stack.empty())
    {
        char op = operator_stack.top();
        if (op == '(')
            throw runtime_error("Unmatched parenthesis.");

        double result = eval_op(op);
        operand_stack.push(result);

        operator_stack.pop();
    }

    if (operand_stack.empty())
        throw runtime_error("Syntax Error: Stack empty in eval_op.");

    double answer = operand_stack.top();
    operand_stack.pop();

    // 답 출력
    if (operand_stack.empty())
        return answer;

    else
    {
        throw runtime_error("Syntax Error: Stack should be empty.");
    }
}

// ==================================== 기타 기능 함수 ===========================================

/**
 * @brief 사용자의 입력에서 공백을 다 없애는 함수
 * 
 * @param input 사용자의 입력
 */
void deleteSpace(string &input) { 
    // 공백을 찾아서 해당 공백이 있는 이터레이터를 이용해 erase
    while(input.find(' ') != string::npos) {
        input.erase(input.begin()+input.find(' '));
    }
}

int main()
{
    string infix;
    getline(cin, infix);
    deleteSpace(infix);

    double result = convertAndCalculate(infix);
    cout << result;
    
    return 0;
}
