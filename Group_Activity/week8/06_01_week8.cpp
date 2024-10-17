#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> mylist;
    list<int>::iterator it1, it2;

    for (int i=1; i<10; ++i)
        mylist.push_back(i*10);     // 10 20 30 40 50 60 70 80 90

    it1= it2 = mylist.begin();
    advance(it2, 6);        // 6칸 앞으로 it2를 옮기세요 - 70

    ++it1;                  // 20

    // erase 되어도 자신의 위치가 erase되지 않은 이상 iterator는 그대로 유지, erase함수는 지운 위치의 다음 iterator를 반환
    it1 = mylist.erase(it1);    // 10 30 40 50 60 70 80 90 - it1 == 30, it2 == 70
    it2 = mylist.erase(it2);    // 10 30 40 50 60 80 90 - it1 == 30, it2 == 80
    ++it1;      // 40
    --it2;      // 60
    // iterator를 이용해서 범위 삭제 시 항상 .end()함수 생각해보자. end() 함수 사용하려면 마지막부분이 포함되면 안된다.
    mylist.erase(it1, it2);     // 10 30 60 80 90

    for(it1 = mylist.begin(); it1 != mylist.end(); ++it1)
        cout << ' ' << *it1;
    cout << '\n';
    
    return 0;
}
