#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 표준 라이브러리를 이용하여 나만의 자료구조를 구현
template <typename Cont>
class Stack
{
private:
    Cont c; // Cont - Container

public:
    typedef typename Cont::value_type value_type; // Cont의 value type을 value_type으로 정의
    bool empty()
    {
        return c.empty();
    }
    int size()
    {
        return c.size();
    }
    value_type &top()
    {
        return c.back();
    }
    void push(value_type x)
    {
        c.push_back(x);
    }
    void pop()
    {
        c.pop_back();
    }
};

int main()
{
    Stack<vector<string>> stack1;
    Stack<list<int>> stack2;

    stack1.push("hello");
    stack2.push(100);

    cout << stack1.top() << ' ' << stack2.top() << endl;

    if (!stack1.empty())
        stack1.pop();
    return 0;
}