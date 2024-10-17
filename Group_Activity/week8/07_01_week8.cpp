#include <iostream>
#include <list>  
using namespace std;

int main()
{
    list<int> mylist1, mylist2;
    list<int>::iterator it;

    for (int i = 1; i <= 4; i++)    // mylist1 1 2 3 4
        mylist1.push_back(i);

    for (int i = 1; i <= 3; ++i)    // mylist2 1 2 3
        mylist2.push_back(i*10);

    it = mylist1.begin();           // mylist1 1
    ++it;                           // mylist1 2

    mylist1.splice(it, mylist2);    // mylist1 1 10 20 30 2 3 4 - insert와 동일한 방식으로 들어간다.
                                    // mylist2 (empty)
    // mylist1의 it 내의 요소를 mylist2.begin 포지션에 넣는다.                                
    mylist2.splice(mylist2.begin(), mylist1, it);   // mylist1 1 10 20 30 3 4
                                                    // mylist2 2 - it은 이제 사용불가

    it = mylist1.begin();       // mylist1 1
    advance(it,3);              // mylist1 30


    // mylist1의 it에서 mylist1.end() 앞까지의 요소를 mylist1.begin포지션에 넣는다.
    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());    // mylist1 30 3 4 1 10 20

    for (it = mylist1.begin(); it != mylist1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    for (it = mylist2.begin(); it != mylist2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    
    return 0;
}
