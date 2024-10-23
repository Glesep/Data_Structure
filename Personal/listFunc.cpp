#include <iostream>
#include <list>
using namespace std;

// list는 []연산자 사용불가
// mylist.func 형식으로 검색하자
// advance(it, 6) 6칸 앞으로 iterator 옮기기
// splice : 오려넣기
// remove(n) : n에 해당하는 값 모두 삭제
// remove_if(condition) : condition이 true인 것 삭제
// unique : 중복 삭제 - 조건에 맞는 중복도 삭제 가능, 검색 ㄱㄱ
// merge : 정렬 후 사용하여야 됨 (sort), binary sort인거같음
// reverse : 순서를 역으로 바꿈
// sort(condition) : condition이 true인대로 정렬
int main()
{
    list<int> mylist(2, 100);
    list<int> list1;
    // list.push_front(n) : n을 리스트의 맨 앞에 삽입
    mylist.push_front(300);
    for (auto i : mylist)
        cout << i << " ";
    cout << '\n';

    // list.assign(개수, 수치) : 개수만큼 list에 수치를 넣음
    list1.assign(5, 400);
    for (auto i : list1)
        cout << i << " ";
    cout << '\n';
    
    
   
    return 0;
}
