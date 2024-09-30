#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(5);
    int i = 0;
    vector<int>::reverse_iterator rit = v.rbegin();
    for (; rit != v.rend(); ++rit)  // 5 4 3 2 1  -  전위 연산자 생각
        *rit = ++i;
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;     
    cout << '\n';
    return 0;
}