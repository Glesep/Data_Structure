#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    list<int> mylist;
    for (int i=1; i<=5; i++)
        mylist.push_back(i);

    list<int>::iterator it = mylist.begin();
    ++it;

    mylist.insert(it,10);
    mylist.insert(it, 2, 20);
    --it;

    vector<int> myvector(2,30);

    mylist.insert(it, myvector.begin(), myvector.end());    // 벡터의 이터레이터를 이용해서 벡터 내 요소들을 list에 insert할 수 있다.

    for (it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    
    return 0;
}
