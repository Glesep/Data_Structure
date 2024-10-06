#include <iostream>
    
using namespace std;
/*
이중 연결 리스트 관련 기능을 구현한 함수들
*/

struct Node
{
    string data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;
Node *tail = nullptr;

void add_after(Node *pre, string item)
{
    // 새로운 노드 구성
    Node *new_node = new Node;
    new_node->data = item;
    new_node->prev = nullptr;
    new_node->next = nullptr;

    // 1. empty list에 삽입할 경우
    if (pre == nullptr && head == nullptr) {
        head = new_node;
        tail = new_node;
    }
    // 2. 맨 앞에 삽입하는 경우
    else if (pre == nullptr) {
        // 관계 짓고
        new_node->next = head;
        head->prev = new_node;
        // 맨 앞 위치 재설정
        head = new_node;
    }
    // 3. 맨 뒤에 삽입하는 경우
    else if(pre == tail){
        // 관계 짓고
        new_node->prev = tail;
        tail->next = new_node;
        // 맨 뒤 위치 재설정
        tail = new_node;
    }
    // 4. 일반적인 경우
    else {
        // new_node측에서 관계 맺고
        new_node->prev = pre;
        new_node->next = pre->next;

        // 각각에서 관계 맺어주기 - 길을 끊어버리면 안됨
        pre->next->prev = new_node;
        pre->next = new_node;

    }
}

void remove(Node *p) {
    // 0. 이상한 경우들
    if (head == nullptr || p == nullptr)
        return;

    // 1. 연결 리스트 내의 유일한 노드일 떄
    if (p == head && p == tail)
        head = tail = nullptr;

    // 2. 첫 번째 노드일 경우
    else if (p == head){
        head = head->next;
        head->prev = nullptr;
    }

    // 3. 마지막 노드인 경우
    else if (p == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    
    // 4. 일반적인 경우
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    delete p;   // garbage 삭제
}

void add_ordered_list(string item) {
    Node *p = tail;
    while (p!=nullptr && item < p->data)
        p = p->prev;
    
    add_after(p, item);
}

