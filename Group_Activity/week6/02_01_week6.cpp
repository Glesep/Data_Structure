#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *add_first(Node *head, int d) {
    Node *p = new Node;
    p->data = d;
    p->next = head;
    return p;
}

/*
1. empty list
2. 하나밖에 없음
3. 여러개
*/
void remove_multiple_three(Node *&head) {
    Node *p = head;
    Node *q = nullptr;
    
    while(p->data % 3 != 0 && p != nullptr) {
        q = p;
        p = p->next;
    }

    // 1. 3의 배수가 없을 떄 or empty list
    if (p == nullptr)
        return;

    // 2. 3의 배수가 있을 때

    // 2-1. 첫 번째 노드가 3의 배수일 때
    if (q == nullptr) {

        // 아래의 두 case 합쳐주기
        // 단독 노드일 때
        if (p->next == nullptr)
            head = nullptr; // 포인터도 값에 의한 호출 주의!!!!!!!! - 주소 자체만 바꾸면 값에 의한 호출 생각해야함
        // 단독 노드가 아닐 때
        else
            head = p->next;
    }
    
    // 2-2. 나머지 경우일 때
    else {
        q->next = p->next;
    }


    delete p;
}

int main()
{
    vector<int> vals{1,2,3};
    Node *head = nullptr;
    
    for (int i : vals) {
        head = add_first(head, i);
    }
    // head = add_first(head, 3);

    remove_multiple_three(head);

    // head가 nullptr이 안됨
    Node *p = head;
    if (p == nullptr)
        cout << "There is no number" << endl;

    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }

    
    return 0;
}
