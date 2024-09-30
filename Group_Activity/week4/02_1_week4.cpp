#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> g1;
    for (int i = 0; i < 5; i++) // 0 1 2 3 4
        g1.push_back(i);

    cout << "Size : " << g1.size() << endl; // 5
    cout << "Capacity : " << g1.capacity() << endl; // 8    - 아마 array doubling

    g1.resize(10);
    cout << "Size : " << g1.size() << endl; // 10
    cout << "Capacity : " << g1.capacity() << endl; // 10    - resize한 대로 따라감

    g1.push_back(9);

    cout << "Capacity : " << g1.capacity() << endl; // 20    - 아마 array doubling

    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << " ";

    return 0;
}