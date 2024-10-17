#include <iostream>
#include <list>
using namespace std;
void print(list<string> &lst)
{
    for (auto it = lst.begin(); it != lst.end(); it++)  // vector와 마찬가지로 iterator 제공
        cout << *it << " ";
    cout << endl;
}
int main()
{
    list<string> empty_lst;
    list<string> lst = {"C++", "list"};                 // vector와 유사하게 list 생성
    // cout << lst[0] << endl; // Not supported         // vector와 달리 at 함수나 [] 연산자를 지원하지 않는다.
    // cout << lst.at(0) << endl; // Not supported
    
    // 지원하는 멤버함수들
    lst.push_front("hello");
    lst.push_back("class");
    lst.push_back("template");
    cout << lst.size() << endl;

    lst.pop_back();
    list<string>::iterator it = lst.begin();

    it++;   // it = next(it)과 동일한 의미, next함수는 iterator 자체를 바꾸는 것이 아니라 바뀐 iterator 값을 반환해주는 것을 유의하자
    cout << *it << endl;
    it = lst.end();
    it--;   // it = prev(it)과 동일한 의미. next함수와 같은 이유로 유의해야한다.
    cout << *it << endl;

    print(lst);

    list<string>::iterator it2 = lst.begin();
    it2 = next(it2, 2);     // 2칸 전진한다.
    it2 = lst.insert(it2, "doubly");        // insert 함수를 지원한다. vector와 동일한 사용법이다.
    print(lst);
    it2 = lst.erase(it2);                   // erase 함수를 지원한다. vector와 동일한 사용법이다.
    print(lst);
    return 0;
}