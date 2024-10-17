#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> first(3, 100);    // first = 100, 100, 100
    list<int> second(5, 200);   // second = 200, 200, 200, 200, 200
    first.swap(second);         // first와 second swap

    for (auto it = first.begin(); it!=first.end(); it++)        // 200 200 200 200 200
        cout << ' ' << *it;
    cout << '\n';
    
    return 0;
}
