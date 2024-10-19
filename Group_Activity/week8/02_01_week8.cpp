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

Node *merge(Node *first, Node *second) {
    // 0. 둘 다 empty list, 혹은 second만 empty list
    if ((first == nullptr && second == nullptr) || second == nullptr) {
        return first;
    }
    // 1. first만 empty list
    else if (first == nullptr) {
        return second;
    }

    // 2. 둘 다 empty list가 아닌 경우
    else {
        Node *mergeSortedHeader = nullptr;
        Node *p = nullptr;
       
        while (first != nullptr && second != nullptr) {
            // 임시 노드 포인터 자체를 nullptr에 가리키게 두지 마라. 그러면 노드포인터의 의미가 없어진다.

            if (first->data < second->data) {
                if (mergeSortedHeader == nullptr) {
                    mergeSortedHeader = first;
                    first = first->next;

                    mergeSortedHeader->next = nullptr;
                    p = mergeSortedHeader;
                }

                else {
                    p->next = first;
                    first = first->next; 

                    p = p->next;
                    p->next = nullptr;
                }
            }

            else if (first->data > second->data) {
                if (mergeSortedHeader == nullptr) {
                    mergeSortedHeader = second;
                    second = second->next;

                    mergeSortedHeader->next = nullptr;
                    p = mergeSortedHeader;
                }

                else {
                    p->next = second;
                    second = second->next; 

                    p = p->next;
                    p->next = nullptr;
                }
            }

            else {
                if (mergeSortedHeader == nullptr) {
                    mergeSortedHeader = first;
                    first = first->next;

                    mergeSortedHeader->next = nullptr;
                    p = mergeSortedHeader;

                    Node *tmp = second;
                    second = second->next;

                    delete tmp;
                }

                else {
                    p->next = first;
                    first = first->next; 

                    p = p->next;
                    p->next = nullptr;

                    Node *tmp = second;
                    second = second->next;

                    delete tmp;
                }
            }
        }

        if (first != nullptr) {
            p->next = first;
            first = nullptr;
        }

        else if (second != nullptr) {
            p->next = second;
            second = nullptr;
        }
        
        return mergeSortedHeader;
    }
}


int main()
{
    Node *head_first = nullptr;
    Node *head_second = nullptr;
    for (int i = 8; i >= 1; i /= 2) {
        head_first = add_first(head_first, i);
    }

    for (int i = 9; i >= 1; i /= 3) {
        head_second = add_first(head_second, i);
    }

    Node *p = head_first;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    p = head_second;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';

    Node *result_header = merge(head_first, head_second);

    p = result_header;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << '\n';
    
    
    return 0;
}
