/*
연결 리스트 기초
*/

#include <iostream>
    
using namespace std;

struct Node {
    string data;    // Data field

    Node *next;     // Link field
};

int main()
{
    Node *head = new Node;

    head->data = "Tuesday";
    head->next = nullptr;

    Node *q = new Node;
    q->data = "Thursday";
    q->next = nullptr;
    head->next = q;

    q = new Node;
    q->data = "Monday";
    q->next = head;
    head = q;       // head는 항상 첫번째 노드의 주소를 가져야한다.

    // 연결 리스트를 순회
    Node *p = head;
    while(p!=nullptr) {
        cout << p->data << endl;
        p = p->next;
    }

    
    return 0;
}
