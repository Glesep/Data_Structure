#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> first{1, 2, 3};
    list<int> second{10, 20, 30, 40, 50};

    second = first;
    auto it = first.begin();
    *it = 100;

    for (auto a : first)        // 100 2 3
        cout << a << ' ';
    cout << endl;

    for (auto b : second)       // 1 2 3
        cout << b << ' ';
    cout << endl;

    for (auto &c : second)      // 2 3 4
        c += 1;
    for (auto c : second)
        cout << c << ' ';
    cout << endl;

    return 0;
}