#include <iostream>

using namespace std;

/*
단일 연결리스트 관련 기능을 구현한 함수들
*/

struct Node
{
    string data; // Data field

    Node *next; // Link field
};

Node *head = nullptr;


//==========================================================================================


// 연결리스트의 맨 앞에 새로운 노드를 삽입하는 함수
void add_first(string item)
{
    Node *tmp = new Node;
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}

// 해당 노드 뒤에 노드 추가
void add_after(Node *prev, string item) {
    if (prev == nullptr)
        return;

    Node *tmp = new Node;
    tmp->data = item;
    tmp->next = prev->next;     // prev->next의 알맹이
    prev->next = tmp;           // prev->next의 공간
}


// 첫번째 노드 삭제
Node *remove_first() {
    if (head == nullptr)    // empty list인 경우
        return nullptr;
    
    else {
        Node *tmp = head;
        head = head->next;  // 첫번째 노드의 다음 노드를 첫번째 노드로 설정
        return tmp;         // 첫번째 노드였던 주소를 반환
    }
}

// 해당 노드 뒤의 노드를 삭제
Node *remove_after(Node *prev) {
    Node *tmp = prev->next;

    if(tmp == nullptr)
        return nullptr;
    else {
        prev->next = tmp->next; // tmp->next == prev->next->next, prev의 다음 노드를 그 다음 노드로 설정
        return tmp;
    }
}

// 노드 내의 data가 일치하면 해당 노드의 주소를 반환
Node *find(string word) {
    Node *p = head;
    while (p!=nullptr) {
        if (p->data == word)
            return p;
        p = p->next;
    }

    return nullptr;
}

// 원하는 인덱스에 해당하는 노드의 주소 반환
Node *get_node(int index) {
    if(index < 0)
        return nullptr;
    Node *p = head;
    for (int i = 0; i<index && p!=nullptr; i++)     // 내가 원하는 인덱스일때까지, 혹은 p가 nullptr이 아닐때까지 반복한다.
        p = p->next;
    return p;
}

// target index에 Node 삽입
bool insert(int index, string item) {
    if (index < 0)
        return false;

    // 첫번째 노드 위치에 삽입 시
    if (index == 0) {
        add_first(item);
        return true;
    }

    // 일반적인 경우일 시
    /*
    항상 단일 연결리스트의 기능적인 부분에선 target 노드 이전의 노드 주소가 중요해진다.
    왜냐하면 노드는 자신 이후의 노드 주소 값밖에 가지지 않기 때문이다.
    */
    Node *prev = get_node(index-1);     
    if (prev != nullptr) {
        add_after(prev, item);
        return true;
    }

    return false;
}

// target index에 해당하는 노드 삭제
Node *remove(int index) {
    if (index < 0)
        return nullptr;

    // 첫번째 노드 삭제 시
    if (index == 0)
        return remove_first();

    // 일반적인 경우일 시
    Node *prev = get_node(index-1);

    if (prev == nullptr)    // 이상한 경우
        return nullptr;
    else
        return remove_after(prev);
}

// data에 item과 같은 값을 가진 node를 삭제
Node *remove(string item) {
    /*
    항상 단일 연결리스트의 기능적인 부분에선 target 노드 이전의 노드 주소가 중요해진다.
    왜냐하면 노드는 자신 이후의 노드 주소 값밖에 가지지 않기 때문이다.

    항상 현재 노드 이전의 노드 주소를 확보하기 위해서 q라는 포인터를 하나 더 정의해준다.
    */
    Node *p = head;
    Node *q = nullptr;
    while (p!=nullptr && p->data!=item) {
        q = p;
        p = p->next;
    }

    if (p == nullptr)   // p가 nullptr - empty list
        return nullptr;
    if (q == nullptr)   // q가 nullptr - while문 돌지 않음 - 첫번째 노드가 대상
        return remove_first();
    else
        return remove_after(q);
}

// data 오름차순으로 Node 삽입
void ordered_insert(string item) {
    Node *p = head;
    Node *q = nullptr;

    /*
    삽입한다 == target 위치에 있는 기존 Node를 뒤로 밀어내고 그 자리에 넣는다.
    -> item < p->data가 처음 됐을 때
    */
    while (p!=nullptr && p->data <= item) {
        q = p;
        p = p->next;
    }

    if (q == nullptr) 
        add_first(item);
    else
        add_after(q, item);
}