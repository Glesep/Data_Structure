#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ArrayStack
{
private:
    int stackSize = 4;
    T *stack = new T[stackSize];
    int top_pos = -1;


public:
    void ArrayReallocation() {
        T *tmp = new T[stackSize*2];

        for (int i=0; i < stackSize; i++) {
            tmp[i] = stack[i];
        }

        delete[] stack;       // 배열 동적할당 시 [] 추가하는 것 기억하기
        stack = tmp;

        stackSize *= 2;
    }

    bool full()
    {
        return top_pos == stackSize - 1;
    }

    bool empty()
    {
        return top_pos == -1;
    }

    void push(T c)
    {
        if (full()) {
            ArrayReallocation();
        }
            
        stack[++top_pos] = c;
    }

    T pop()
    {
        if (empty())
            throw runtime_error("stack_empty");
        return stack[top_pos--];    // 반환 후 스택 삭제
    }

    T top()
    {
        if (empty())
            throw runtime_error("stack_empty");
        return stack[top_pos];
    }

    void debug() {
        cout << stackSize << endl;
    }
};

const string OPERATORS = "()";
const int PRECEDENCE[] = {1, 0}; // '(' 과 ')'을 구분하기 위한 배열 정의

/**
 * @brief 괄호인지 아닌지 구분
 * 
 * @param ch 괄호
 * @return 열린 괄호 == 1, 닫힌 괄호 == 0, 다른 문자 == -1
 */
int judge_parentheses(char ch) {

    if (OPERATORS.find(ch) != string::npos)
        return PRECEDENCE[OPERATORS.find(ch)];
    else
        return -1;
}

/**
 * @brief 괄호의 열리고 닫힘을 알려주는 함수
 * 
 * @param stack 스택 객체
 * @param seq 열려있는 괄호의 순서 판단 변수
 * @param jp judge_parentheses의 결과값
 * @return int -1일 땐 괄호가 아님
 */
int return_sequence(ArrayStack<int> &stack, int &seq, int jp) {
    // 1. 열린 괄호일 때
    if (jp == 1) {
        stack.push(++seq);
        return seq;
    }

    // 2. 닫힌 괄호일 때
    else if (jp == 0) {
        return stack.pop();
    }

    // 3. 괄호가 아닐 때
    return jp;
}

int main()
{
    int sequence = 0;   // 괄호의 순서를 매길 변수 정의
    string input;
    ArrayStack<int> stack;   // stack 구현

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        int jp = judge_parentheses(input[i]);
        int result = return_sequence(stack, sequence, jp);  // 결과 값을 변수에 저장

        if (result == -1)
            continue;

        else {
            cout << result << " ";
        }
    }

    cout << '\n';
    
    return 0;
}
