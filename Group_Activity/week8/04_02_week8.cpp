#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> first;
    list<int> second;

    first.assign(5, 100);       // 100 100 100 100 100
    second.assign(first.begin(), first.end());  // 100 100 100 100 100

    int myints[] = {17, 7, 4};
    first.assign(myints, myints + 3);   // 17 7 4   - 기존 내용 삭제

    for (auto a : first)
        cout << a << ' ';
    cout << endl;

    for (auto b : second)
        cout << b << ' ';
    cout << endl;
    return 0;
}