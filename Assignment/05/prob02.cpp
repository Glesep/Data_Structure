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

void equal_or_lessThan(int num, ArrayStack<int> &stack) {
    // 빈 스택이 아닐 때
    if (!stack.empty()) {
        while (stack.top() <= num) {    // 문제의 조건과 같으면
            stack.pop();
        }
    }

    stack.push(num);
}

int main()
{
    int N;
    cin >> N;
    
    ArrayStack<int> stack;  // 스택 생성


    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        // 자신보다 작거나 같은 정수들을 모두 제거
        
        // 자신을 포함하여 남아있는 정수들의 개수 출력
    }
    
    return 0;
}
