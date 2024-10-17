#include <iostream>

using namespace std;



/*
n개의 단어를 입력받아서 사전식 순서로 이중 연결리스트에 저장한 후 중복된 단어를 찾아서 제거하는 일을 한다.
*/
struct Node
{
    string data;
    Node *prev, *next;
};

void ordered_insert(string item);
void remove_dup();
void print_list_twice();

Node *head = nullptr, *tail = nullptr; /* 2중 연결리스트의 처음과 마지막 노드 */

int main()
{
    int n;
    string word;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        ordered_insert(word);
    }

    print_list_twice();
    remove_dup();
    print_list_twice();
    return 0;
}

/**
 * @brief head와 tail이 가리키는 2중 연결리스트에 문자열들이 사전식 순서로 정렬된 순서를 유지하도록 새로운 문자열 item을 삽입한다.
 * 
 * @param item 노드 내의 데이터에 들어갈 문자열
 */
void ordered_insert(string item)
{
    // 들어갈 위치 찾기
    Node *pre = tail;
    while (pre != nullptr && item < pre->data)
        pre = pre->prev;

    // 1. 추가될 노드 정의
    Node *new_node = new Node;
    new_node->data = item;
    new_node->prev = nullptr;
    new_node->next = nullptr;

    // 2. empty list에 삽입할 경우
    if (pre == nullptr && head == nullptr) {
        head = new_node;
        tail = new_node;
    }

    // 3. 맨 앞에 삽입하는 경우
    else if (pre == nullptr) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    // 4. 맨 뒤에 삽입되는 경우
    else if (pre ==tail) {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    
    // 5. 일반적인 경우
    else {
        new_node->next = pre->next;
        new_node->prev = pre;

        pre->next->prev = new_node;
        pre->next = new_node;
    }

}

/**
 * @brief 2중 연결리스트에 저정된 문자열들 중에서 모든 중복된 문자열을 찾아 하나만 남기고 제거한다.
 * 어느 한 노드를 기준으로 삼은 후, 중복이 아닌 노드까지 진행한 후 기준 노드와 중복이 아닌 노드를 이어주기
 * 특이 케이스 1) 중복 이후 노드가 nullptr
 * 특이 케이스 2) empty list
 */
void remove_dup()
{
    Node *current_node = head;
    // 1. empty list인 경우
    if (head == nullptr && tail == nullptr)
        return;

    while (current_node != nullptr) {
        Node *dup_node = current_node;

        // 중복 찾기
        while(dup_node->next != nullptr) {
            if (dup_node->next->data != dup_node->data)
                break;
            
            dup_node = dup_node->next;
        }

        // 2. 중복 이후 노드가 nullptr
        if (dup_node->next == nullptr) {
            current_node->next = nullptr;
            tail = current_node;
        }

        // 3. 일반적인 경우 (중복 없는 경우도 여기 포함)
        else {
            dup_node->next->prev = current_node;
            current_node->next = dup_node->next;
        }

        current_node = current_node->next;
    }
}

/**
 * @brief 이중 연결리스트의 노드 내부 데이터를 순차적으로 한번, 역순으로 한번 출력해주는 함수
 * 
 */
void print_list_twice()
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    Node *q = tail;
    while (q != nullptr)
    {
        cout << q->data << " ";
        q = q->prev;
    }
    cout << endl;
}
