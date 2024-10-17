#include <iostream>
#include <list>
using namespace std;

int main()
{
    int myints[] = {17, 89, 7, 89, 14};

    // iterator를 이용해서 list 만들기, 항상 마지막 이터레이터 앞까지 받아들임
    list<int> mylist (myints, myints+5);        // 17 89 7 89 14

     for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    
    // erase와는 달리 해당되는 값과 똑같은 값을 가진 모든 요소 삭제
    mylist.remove(89);                          // 17 7 14

    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    
    return 0;
}
