#include <iostream>
#include <string>
using namespace std;

// const int MAX_CAPACITY = 100;
template <typename T>
class ArrayStack
{
private:
    T *stack = new T[4];
    int top_pos = -1;

public:
    // T *stack = new T[4];
    typedef typename T::value_type value_type; // Cont의 value type을 value_type으로 정의

    void ArrayReallocation() {
        int stackSize = sizeof(stack) / sizeof(value_type);
        
        T *tmp = new T[stackSize*2];

        for (int i=0; i < stackSize; i++) {
            tmp[i] = stack[i];
        }

        delete stack;       // error
        stack = tmp;
    }
    bool full()
    {
        return top_pos == stack->size() - 1;
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
};
int main()
{
    ArrayStack<string> s1;
    for (int i = 0; i < 5; i ++) {
        s1.push("hi");
    }

    // ArrayStack<string> s1;

    // string a[4];

    // cout << sizeof(a) / sizeof(string) << endl;
    // // s1.stack.size();
    

    
}
