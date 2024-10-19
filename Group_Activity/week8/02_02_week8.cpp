#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *add_first(Node *head, int d)
{
    Node *p = new Node;
    p->data = d;
    p->next = head;
    return p;
}
void func(Node *&head)
{
    Node *p = head, *q = nullptr;
    while (p != nullptr)
    {
        if (p->data < 0) {
            // 첫 노드가 음수일 경우를 생각해야 함
            if (q == nullptr) {
                head = head->next;
                p = head;
                continue;
            }
            else 
                q->next = p->next;
        }
        else
            q = p;
        p = p->next;
    }
}
int main()
{
    Node *head = nullptr;

    for (int i = 10; i > 0; i--) {
        int tmp = i;
        if (tmp % 2 != 0) 
            tmp *= -1;
  
        head = add_first(head, tmp);
    }

    Node *p = head;
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    func(head);

    p = head;
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    return 0;
}
