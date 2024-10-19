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

Node *remove_inRange(Node *list, int lower, int upper) {
    Node *p = list;
    Node *q = nullptr;

    // 0. empty list
    if (p == nullptr)
        return p;

    // lower보다 크거나 같은 첫 번째 노드의 전 노드 찾기

    // 첫 번째 노드가 lower보다 크거나 같을 때
    if (p->data >= lower) {
        // 첫 번째 노드가 upper보다 클 때
        if (p->data > upper)
            return list;

        while (p != nullptr) {
            // 조건문에 nullptr에서 접근될 수 있는 문장은 쓰지말자
            if (p->data > upper)
                break;

            q = p;
            p = p->next;
        }

        // 모든 노드의 값이 upper보다 작거나 같을 때
        if (p == nullptr) {
            return nullptr;
        }
        // upper보다 큰 값이 있을 때
        else {
            list = p;
        }

        return list;
    }

    else {
        // lower보다 크거나 같은 첫 번째 노드의 전 노드 찾기
        while (p != nullptr) {
            if (p->data >= lower)
                break;
            q = p;
            p = p->next;
        }

        // lower보다 크거나 같은 값이 없을 때
        if (p == nullptr) 
            return list;
        
        else {
            // lower보다 큰 값을 가진 첫 번째 노드의 이전 노드
            Node *target_LO_prev = q;

            while ( p != nullptr) {
                
                if (p->data > upper)
                    break;
                q = p;
                p = p->next;
            }

            // 이후 모든 노드의 값이 upper보다 작거나 같을 때
            if (p == nullptr) {
                target_LO_prev->next = nullptr;
                return list;
            }
            // 이후 upper보다 큰 값이 있을 때
            else {
                Node *target_UP_prev = q;

                target_LO_prev->next = target_UP_prev->next;
                return list;
            }
        }
    }

}

int main()
{
    Node *head = nullptr;

    for (int i = 10; i > 0; i--) {
        head = add_first(head, i);
    }

    Node *p = head;
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    head = remove_inRange(head, 3, 6);

    p = head;
    if (p == nullptr) {
        cout << "Empty List!" << endl;
        return 0;
    }
    while(p!=nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
    
    return 0;
}
