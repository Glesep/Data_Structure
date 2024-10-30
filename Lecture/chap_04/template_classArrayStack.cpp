#include <iostream>

using namespace std;

const int MAX_CAPACITY = 100;
template <typename T>
class ArrayStack
{
private:
    T stack[MAX_CAPACITY];
    int top_pos = -1;

public:
    bool full()
    {
        return top_pos == MAX_CAPACITY - 1;
    }
    bool empty()
    {
        return top_pos == -1;
    }
    void push(T c)
    {
        if (full())
            throw runtime_error("stack_full");
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
    s1.push("hello");
    ArrayStack<int> s2;
    s2.push(100);
    cout << s1.top() << ' ' << s2.top() << endl;
}
