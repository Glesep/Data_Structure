#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};


Node *add_first(Node *head, int d) {
    Node *p = new Node;
    p->data = d;
    p->next = head;
    return p;
}
// 서로 다른 정수의 개수를 기록하는 함수
// j가 서로 다른 정수의 개수를 저장하는 변수의 주소를 담고있는 포인터
Node *func(Node *head, int *j)
{
    Node *t1, *t2;
    *j = 0;
    t1 = head;
    if (t1 != nullptr)
        t2 = t1->next;
    else
        return head;
    *j = 1;
    if (t2 == nullptr)
        return head;
    while (t2 != nullptr)
    {
        if (t1->data != t2->data) // (S1)
        {
            // (S2)
            (*j)++;
            t1->next = t2;
            t1 = t2; 
        }
        t2 = t2->next;
    }
    t1->next = nullptr;
    return head;
}
int main()
{
    Node *head = nullptr;
    int count;

    for (int i = 7; i > 0; i--) {
        head = add_first(head, i);
    }

    Node *p = head;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    head = func(head, &count);
    cout << count << "개" << endl;

    return 0;
}
