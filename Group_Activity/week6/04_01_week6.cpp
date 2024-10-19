// 연습용코드
//  연결리스트는 내부값을 바꾸는 일을 잘 하지 않는다.

#include <iostream>
    
using namespace std;
struct Node
{
    int value;
    Node *next;
};

Node *add_first(Node *head, int d) {
    Node *p = new Node;
    p->value = d;
    p->next = head;
    return p;
}

void rearrange(Node *list)
{
    Node *p, *q;
    int temp;
    // empty list 또는 단일 노드
    if (list == nullptr || list->next == nullptr)
        return;

    p = list;
    q = list->next;

    while (q != nullptr)
    {
        temp = p->value;
        p->value = q->value;
        q->value = temp;
        p = q->next;
        q = (p != nullptr ? p->next : 0);
    }
}

int main()
{
    Node *head = nullptr;

    for (int i = 7; i > 0; i--) {
        head = add_first(head, i);
    }

    Node *p = head;

    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << '\n';

    rearrange(head);

    p = head;
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << '\n';
    return 0;
}
