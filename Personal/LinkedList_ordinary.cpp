#include <iostream>
    
using namespace std;

struct Node {
    int data;

    Node *next;
};

Node *head = nullptr;

void add_first(int item)
{
    Node *tmp = new Node;
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}

void add_after(Node *prev, int item) {
    if (prev == nullptr)
        return;

    Node *tmp = new Node;
    tmp->data = item;
    tmp->next = prev->next;     // prev->next의 알맹이
    prev->next = tmp;           // prev->next의 공간
}

/**
 * @brief 한 노드를 다른 연결리스트의 맨 앞에 삽입하는 노드
 * 
 * @param target 대상 노드 (default 값: prev->next)
 */
void add_first_NodeVer(Node *&head_forInsert, Node *target) {
    target->next = head_forInsert;
    head_forInsert = target;
}

/**
 * @brief 한 노드를 다른 연결리스트의 사이에 넣는 함수
 * 
 * @param prev 다른 연결리스트의 삽입 위치 전을 의미하는 노드
 * @param target 삽입될 노드
 */
void add_after_NodeVer(Node *prev, Node *target) {

    // 1. 맨 끝에 삽입
    if (prev->next == nullptr) {
        prev->next = target;
    }

    // 2. 중간에 삽입
    else {
        target->next = prev->next;
        prev->next = target;
    }
}


/**
 * @brief 오름차순으로 정렬된 연결리스트를 반환하는 함수 (기존의 연결리스트의 구성으로 만듦, 기존 연결리스트는 유지됨)
 * 
 * @param target_head 오름차순 정렬할 연결리스트
 * @return Node* 정렬된 연결리스트의 head 노드
 */
Node *ASC_list (Node *target_head) {

    if (target_head == nullptr)
        return target_head;

    Node *ASC_LL_head = nullptr;


    while(target_head != nullptr) {
        Node *p = target_head;
        Node *q = nullptr;

        Node *min_prevPtr = nullptr;
        int min = target_head->data;

        // 최소 체크
        while (p != nullptr) {
            if (p->data < min) {
                min = p->data;
                min_prevPtr = q;
            }

            q = p;
            p = p->next;
        }

        // 맨 첫번째 노드가 최소일 때
        if (min_prevPtr == nullptr) {

            Node *r = ASC_LL_head;
            Node *s = nullptr;

            while (r!=nullptr && r->data <= min) {
                s = r;
                r = r->next;
            }

            Node *tmp = target_head;
            target_head = target_head->next;

            if (s == nullptr) {
                add_first_NodeVer(ASC_LL_head, tmp);
            }
            
            else {
                add_after_NodeVer(s, tmp);
            }
        }
        
        // 일반적 경우
        else {
            Node *r = ASC_LL_head;
            Node *s = nullptr;

            while (r!=nullptr && r->data <= min) {
                s = r;
                r = r->next;
            }

            Node *tmp = min_prevPtr->next;
            min_prevPtr->next = tmp->next;

            if (s == nullptr) {
                add_first_NodeVer(ASC_LL_head, tmp);
            }
            
            else {
                add_after_NodeVer(s, tmp);
            }
        }
    }

    return ASC_LL_head;
}


int main()
{
    Node *p = head;
    // Node *q = nullptr;

    for (int i = 10; i > 0; i--) {
        if (p == nullptr) {
            add_first(i);
            p = head;
        }
        
        else {
            add_after(p, i);
            p = p->next;
        }
    }

    Node * first = head;
    while (first != nullptr) {
        cout << first->data << endl;
        first = first->next;
    }

    cout << "======================================" << endl;

    head = ASC_list(head);

    first = head;
    while (first != nullptr) {
        cout << first->data << endl;
        first = first->next;
    }
    
    return 0;
}
