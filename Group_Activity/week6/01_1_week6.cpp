#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;

    Node *next;
};

Node *head_first = nullptr;
Node *head_second = nullptr;

/**
 * @brief 첫 번째 연결리스트의 맨 끝에 두 번째 연결리스트를 연결하여 하나의 연결리스트로 합치는 함수 
 * 
 * @param first 첫 번째 연결리스트
 * @param second 두 번째 연결리스트
 * @return Node* 새롭게 만들어진 head 노드의 주소
 */
Node *concatenate(Node *first, Node *second) {
    // 0. 이상한 경우
    if (first == nullptr && second == nullptr)
        return nullptr;

    // 1. 첫 번째 연결리스트가 empty list
    if (first == nullptr) 
        return second;
    
    // 2. 두 번째 연결리스트가 empty list
    else if (second == nullptr)
        return first;
    
    // 3. 둘 다 존재
    else {
        Node *p = first;
        
        // 첫 번째 연결리스트의 마지막 노드에 접근
        while(p->next != nullptr) {
            p = p->next;
        }

        p->next = second;

        return first;
    }
}

// debug
int main() {
    // head_first = new Node;
    // head_first->next = nullptr;
    // head_first->data = 1;

    // Node *p = new Node;
    // p->data = 2;
    // p->next = nullptr;
    // head_first->next = p;

    head_second = new Node;
    head_second->next = nullptr;
    head_second->data = 3;

    Node *q = new Node;
    q->next = nullptr;
    q->data = 4;
    head_second->next = q;

    Node *head_result = concatenate(head_first, head_second);

    Node *r = head_result;
    while (r != nullptr) {
        cout << r->data << endl;

        r = r->next;
    }    
}
