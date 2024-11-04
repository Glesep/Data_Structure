#include <iostream>
#include <vector>
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

int stack_count = 0;    // 스택 내부 요소의 개수를 세는 전역변수

/**
 * @brief 각 정수가 주어질 때 마다 이전에 입력된 
정수들 중에서 자신보다 작거나 같은 정수들은 모두 제거한 후 자신을 포함하여 남아있는 정수들의 개
수를 출력
 * 
 * @param num 입력된 정수
 * @param stack stack
 * @return int stack_count
 */
int problemSolveFunc(int num, ArrayStack<int> &stack) {

    // 빈 스택이 아닐 때
    // 조건에는 접근했을 때 오류가 나지 않는 조건을 먼저 쓴다.
    while (!stack.empty() && stack.top() <= num) {    // 문제의 조건과 같으면
        stack.pop();
        stack_count--;
    }

    stack.push(num);

    return ++stack_count;
}


int main()
{
    int N;
    cin >> N;
    
    ArrayStack<int> stack;  // 스택 생성

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        cout << problemSolveFunc(num, stack) << " ";
    }

    cout << endl;
    
    return 0;
}
