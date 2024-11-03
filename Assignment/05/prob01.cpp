#include <iostream>
#include <string>
using namespace std;

// const int MAX_CAPACITY = 100;
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

    void pop()
    {
        if (empty())
            throw runtime_error("stack_empty");
        top_pos--;
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
int main()
{
    ArrayStack<string> s1;

    for (int i = 0; i < 9; i ++) {
        s1.push("hi");
    }

   s1.debug();

    // string a[4] = {"hello", "hi", "sell", "beauty"};
    // int size = sizeof(a) / sizeof(string);

    // cout << size << endl;

    


    // ArrayStack<string> s1;

    // string a[4];

    // cout << sizeof(a) / sizeof(string) << endl;
    // // s1.stack.size();
    

    
}
