#include <iostream>
    
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

// 윗 자릿수보다 크거나 같으면 stack push
// 제거해야되는 횟수가 남으면 pop 후 push 혹은 넣지 않기

ArrayStack<int> stack;

void makeBiggestDigit(int num, int deleteFreq) {
    if (!stack.empty()) {
        
    }
    else
}
int main()
{
    
    
    return 0;
}
