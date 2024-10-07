#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
    string word;
    int count;

    Node *next;
};

Node *head = nullptr;

/*
필요한 것
저장
word 찾기
출력

*/
void set_linkedList();
void print_word(Node *head);
void add_first(string item);
void add_after(Node *prev, string item);
void ASC_insert(string item);
void remove_first();
void remove_after(Node *prev);
void remove(int item);
void DESC_insert(string item);

int main()
{
    // (1)
    set_linkedList();
    // print_word(head);

    // (2)
    remove(10);
    // print_word(head);

    // (3)


    return 0;
}

void set_linkedList()
{
    ifstream infile("harry.txt");
    string word;
    while (infile >> word)
    {
        ASC_insert(word);
    }
    infile.close();
}


void print_word(Node *head)
{
    int n = 0;
    while (head != nullptr)
    {
        cout << head->word << ": " << head->count << endl;
        n++;
        head = head->next;
    }
    cout << n << endl;
}

void add_first(string item)
{
    Node *tmp = new Node;
    tmp->word = item;
    tmp->next = head; // = nullptr
    head = tmp;
}

// 해당 노드 뒤에 노드 추가
void add_after(Node *prev, string item)
{
    if (prev == nullptr)
        return;

    Node *tmp = new Node;
    tmp->word = item;
    tmp->next = prev->next; // prev->next의 알맹이
    prev->next = tmp;       // prev->next의 공간
}

// 노드 내의 data가 일치하면 해당 노드의 주소를 반환
Node *find(string item)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->word == item)
            return p;
        p = p->next;
    }

    return nullptr;
}

// word 오름차순으로 Node 삽입
void ASC_insert(string item)
{
    Node *p = head;
    Node *q = nullptr;

    while (p != nullptr && p->word <= item)
    {
        q = p;
        p = p->next;
    }

    if (find(item) == nullptr)
    { // 중복이 없으면
        if (q == nullptr)
        { // 첫번째 노드에 들어갈 때
            add_first(item);
            head->count = 1;
        }
        else
        { // 나머지
            add_after(q, item);
            q->next->count = 1;
        }
    }
    else
    { // 중복이 있으면
        Node *target = find(item);
        target->count++;
    }
}

// 첫번째 노드 삭제
void remove_first()
{
    if (head == nullptr) // empty list인 경우
        return;

    else
    {
        Node *tmp = head;
        head = head->next; // 첫번째 노드의 다음 노드를 첫번째 노드로 설정

        delete tmp;
    }
}

// 해당 노드 뒤의 노드를 삭제
void remove_after(Node *prev)
{
    Node *tmp = prev->next;

    if (tmp == nullptr)
        return;
    else
    {
        prev->next = tmp->next; // tmp->next == prev->next->next, prev의 다음 노드를 그 다음 노드로 설정
        delete tmp;
    }
}

// counta에 item값 이하인 값을 가진 node를 삭제
void remove(int item)
{
    Node *p = head;
    Node *q = nullptr;
    while (p != nullptr)
    {
        // 
        if (q == nullptr && p->count <= item) {
            // q가 nullptr - 첫번째 노드가 대상
            remove_first();
            p = head;
            continue;
        } 
        else if (p->count <= item) {
            remove_after(q);
            p = q->next;
            continue;
        }
        q = p;
        p = p->next;
    }

    if (p == nullptr) // p가 nullptr - empty list
        return;
}

// 내림차순으로 정렬하며 추가
void DESC_insert(string item) {
    Node *p = head;
    Node *q = nullptr;

    while (p != nullptr && p->word >= item)
    {
        q = p;
        p = p->next;
    }

    if (find(item) == nullptr)
    { // 중복이 없으면
        if (q == nullptr)
        { // 첫번째 노드에 들어갈 때
            add_first(item);
            head->count = 1;
        }
        else
        { // 나머지
            add_after(q, item);
            q->next->count = 1;
        }
    }
    // else
    // { // 중복이 있으면
    //     Node *target = find(item);
    //     target->count++;
    // }
}

