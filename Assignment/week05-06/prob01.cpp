#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    int x, y, w, h;
    Node *next;
};

Node *head = nullptr;
int N = 0;






void print_list()
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->x << " " << p->y << " " << p->w << " " << p->h << endl;
        p = p->next;
    }
}

/**
 * @brief 
 * rects.txt 파일을 읽어서 사각형들을 파일에 저장된 순서대로 
 * head가 가리키는 연결리스트에 저장한다.
 * 
 */
void read_file()
{
    ifstream infile("rects.txt");
    string count;
    string line;
    // 논리적 오류 - Node *p = head 정의 시 p 내부 주소값이 바뀌면 head 주소값도 바뀐다.
    Node *p = nullptr;     // 주소값에 대한 복사, head가 같이 바뀌는게 아님
    

    getline(infile, count); // 사각형의 개수 N 받기
    N = stoi(count);
    
    
    // 한 라인을 받아서 연결리스트에 저장
    while(getline(infile, line)) {
        

        // 첫 번째 노드일 때
        if (head == nullptr) {
            head = new Node;

            stringstream ss(line);
            ss >> head->x >> head->y >> head->w >> head->h;
            head->next = nullptr;

            p = head;
        }

        // 나머지 경우일 때
        else {
            Node *q = new Node;

            stringstream ss(line);
            ss >> q->x >> q->y >> q->w >> q->h;

            q->next = nullptr;  // 중요! - 포인터의 기본 값은 nullptr으로 고정한다고 생각
            p->next = q;
            p = p->next;
        }
    }
}

/**
 * @brief 두 노드의 data swap
 * 
 * @param p 
 * @param pNext 
 */
void swap(Node *p, Node *pNext) {
    Node tmp;
    tmp.x = p->x;
    tmp.y = p->y;
    tmp.w = p->w;
    tmp.h = p->h;

    p->x = pNext->x;
    p->y = pNext->y;
    p->w = pNext->w;
    p->h = pNext->h;

    pNext->x = tmp.x;
    pNext->y = tmp.y;
    pNext->w = tmp.w;
    pNext->h = tmp.h;
}



/**
 * @brief 
 * head가 가리키는 연결리스트를 면적순으로 정렬한다.
 * (Bubble Sorting)
 */
void sort_by_area()
{   
    for (int i = N-1; i > 0; i--) {
        Node *p = head;     // p는 포인터 변수라는 것을 잊지말자
        
        for (int j = 0; j < i && p != nullptr; j++) {
            if ((p->w * p->h) > (p->next->w * p->next->h)) {
                //data만 바꾸기
                swap(p, p->next);
            }
            // 다음 노드로 이동
            p = p->next;
        }
    }
}

// 첫번째 노드 삭제
void remove_first() {
    if (head == nullptr)    // empty list인 경우
        return;
    
    else {
        Node *tmp = head;
        head = head->next;  // 첫번째 노드의 다음 노드를 첫번째 노드로 설정
        delete tmp;         // 첫번째 노드를 삭제
    }
}

// 해당 노드 뒤의 노드를 삭제
void remove_after(Node *prev) {
    Node *tmp = prev->next;

    if(tmp == nullptr)
        return;
    else {
        prev->next = tmp->next; // tmp->next == prev->next->next, prev의 다음 노드를 그 다음 노드로 설정
        delete tmp;
    }
}

void remove_rects(int min_w, int min_h) {
     /*
    항상 단일 연결리스트의 기능적인 부분에선 target 노드 이전의 노드 주소가 중요해진다.
    왜냐하면 노드는 자신 이후의 노드 주소 값밖에 가지지 않기 때문이다.

    항상 현재 노드 이전의 노드 주소를 확보하기 위해서 q라는 포인터를 하나 더 정의해준다.
    */
    Node *p = head;
    Node *q = nullptr;
    while (p!=nullptr && (p->w != min_w || p->h != min_h)) {
        q = p;
        p = p->next;
    }
    
    if (p == nullptr)   // p가 nullptr - empty list
        return;

    if (q == nullptr)   // q가 nullptr - while문 돌지 않음 - 첫번째 노드가 대상
        remove_first();
    else
        remove_after(q);
}

int main()
{
    // (1)
    read_file();    // 파일을 읽어서 파일에 저장된 순서대로 저장된 연결리스트를 구성한다.
    print_list();   // 파일에 저장된 순서대로 출력된다.
    cout << endl;   // 한 줄을 띄운다.
    
    // (2)
    sort_by_area(); // 연결리스트의 노드들을 면적순으로 정렬한다.
    print_list();   // 정렬된 순서대로 출력한다.
    cout << endl; // 한 줄을 띄운다.

    // (3)
    int min_w, min_h;
    cin >> min_w >> min_h;
    remove_rects(min_w, min_h);
    print_list();
    return 0;
}
