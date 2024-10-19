// head를 변경하는 방법
/*
1. 전역변수
2. 참조
3. 주소 반환
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

/**
 * @brief 연결리스트의 순서를 역으로 바꾸는 함수, head 위치를 바꿔주면 될 것 같다.
 * 
 * @param head 순서를 바꾸고 싶은 연결리스트의 헤드노드
 */
Node *func(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
}

int main()
{
    Node *head = nullptr;

    for (int i = 0; i < 4; i++) {
        head = add_first(head, i);
    }

    Node *p = head;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    head = func(head);

    p = head;
    
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
    
    return 0;
}
