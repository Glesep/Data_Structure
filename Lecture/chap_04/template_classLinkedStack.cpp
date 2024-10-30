#include <iostream>
#include <string>
using namespace std;

template <typename S>
class Node
{
    template <typename T>
    friend class LinkedStack;

private:
    S data;
    Node *next;
    Node() {}
    Node(S c, Node *p) : data(c), next(p) {}
};

template <typename T>
class LinkedStack
{
private:
    Node<T> *head = nullptr;

public:
    bool full()
    {
        return false;
    }
    bool empty()
    {
        return head == nullptr;
    }
    void push(T c)
    {
        head = new Node<T>(c, head);
    }
    void pop()
    {
        if (empty())
            throw runtime_error("stack_empty");
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
    T top()
    {
        if (empty())
            throw runtime_error("stack_empty");
        return head->data;
    }
};
int main()
{
    LinkedStack<string> s1;
    LinkedStack<int> s2;
    s1.push("hello");
    s2.push(100);
    cout << s1.top() << ' ' << s2.top() << endl;
}