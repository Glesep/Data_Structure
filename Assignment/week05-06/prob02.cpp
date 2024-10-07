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
Node *DESC_insert(Node *head_ASC);

int main()
{
    // (1)
    set_linkedList();
    print_word(head);

    // (2)
    remove(10);
    print_word(head);

    // (3)
    Node *head_DESC = DESC_insert(head);
    print_word(head_DESC);

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
        if (q == nullptr && p->count <= item)
        {
            // q가 nullptr - 첫번째 노드가 대상
            remove_first();
            p = head;
            continue;
        }
        else if (p->count <= item)
        {
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

// (2)에서 만든 노드를 떼어서 새로운 정렬된 연결리스트에 삽입하는 방식으로 등장빈도 내림차순으로 정렬하며 추가
/*
필요한 것
빈도수 체크 -> 주소 뽑아오기
내림차순으로 저장하는 방법
 */
Node *DESC_insert(Node *head_ASC)
{
    Node *head_DESC = nullptr;

    while (head_ASC != nullptr)
    { // 1. 빈도수 체크
        Node *p_ASC = head_ASC;
        Node *q_ASC = nullptr;
        int MAX_count = p_ASC->count;
        Node *MAX_prePtr = nullptr;

        // 같을 때는 어짜피 사전순 대로 옮겨질 것
        while (p_ASC != nullptr)
        {
            if (MAX_count < p_ASC->count)
            {
                MAX_count = p_ASC->count;
                MAX_prePtr = q_ASC; // 나중에 삭제를 위해 전 주소를 받아옴
            }

            q_ASC = p_ASC;
            p_ASC = p_ASC->next;
        }
        
        // MAX_prePtr는 최고 빈도수를 가지고 있는 노드의 전 주소
        // 내림차순으로 저장
        Node *p_DESC = head_DESC;
        Node *q_DESC = nullptr;

        // MAX_count보다 작아질 때까지 반복
        while (p_DESC != nullptr && p_DESC->count >= MAX_count)
        {
            q_DESC = p_DESC;
            p_DESC = p_DESC->next;
        }

        // DESC의 첫 노드에 삽입할 때
        if (q_DESC == nullptr)
        {
            // 삽입 대상이 ASC의 맨 처음 노드일 때
            if (MAX_prePtr == nullptr)
            {
                // DESC에 추가
                Node *tmp = head_ASC;
                head_DESC = tmp;

                // ASC에서 삭제
                head_ASC = head_ASC->next; // 첫번째 노드의 다음 노드를 첫번째 노드로 설정
                head_DESC->next = nullptr; // = nullptr

                // delete tmp;              // 지우는 게 아니라 DESC로 넘기는 것
            }
            // 삽입 대상이 ASC의 그 외의 노드일 때
            else
            {
                // DESC에 추가
                Node *tmp = MAX_prePtr->next;
                head_DESC = tmp;

                // ASC에서 삭제
                MAX_prePtr->next = tmp->next;
                head_DESC->next = nullptr;

                // delete tmp;      // 지우는 게 아니라 DESC로 넘기는 것
            }
        }

        // DESC의 나머지 노드에 삽입할 때
        else
        { // 나머지

            // 이상한 경우
            if (q_DESC == nullptr)
                return nullptr;

            // 삽입 대상이 ASC의 맨 처음 노드일 때
            if (MAX_prePtr == nullptr)
            {
                // DESC에 추가
                Node *tmp = head_ASC;
                q_DESC->next = tmp;

                // ASC에서 삭제
                head_ASC = head_ASC->next;    // 첫번째 노드의 다음 노드를 첫번째 노드로 설정
                q_DESC->next->next = nullptr; // = nullptr

                // delete tmp;
            }
            // 삽입 대상이 ASC의 그 외의 노드일 때
            else
            {
                // DESC에 추가
                Node *tmp = MAX_prePtr->next;
                q_DESC->next = tmp;

                // ASC에서 삭제
                MAX_prePtr->next = tmp->next;
                q_DESC->next->next = nullptr;

                // delete tmp;
            }
        }
    }

    return head_DESC;
}