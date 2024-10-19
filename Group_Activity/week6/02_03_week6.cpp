/*
연결리스트를 구현할 때는 항상 "Extream case"를 쳐내고 General case를 고려하자
노드가 null일 수 있는 경우를 생각하면 Extream case를 찾을 수 있을 것
*/
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

Node *lastNode_go_first(Node *head) {
    Node *prev = nullptr;
    Node *current = head;

    // prev는 마지막 노드 이전 노드
    while(current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    current->next = head;
    prev->next = nullptr;
    head = current;

    return head;
}

int main()
{
    Node *head = nullptr;

    for (int i = 0; i < 5; i++)
        head = add_first(head, i);

    Node *p = head;
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    head = lastNode_go_first(head);

    p = head;

    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
    
    return 0;
}
