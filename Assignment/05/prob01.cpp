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

    void ArrayReallocation() {
        T *tmp = new T[(int)stack->size()*2];

        for (int i=0; i < stack->size(); i++) {
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

    
}
