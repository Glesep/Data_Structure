#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);        // v1 : 1 2

    v2.push_back(3);    
    v2.push_back(4);
    v2.push_back(5);        // v2 : 3 4 5

    v1.swap(v2);            // v1과 v2를 바꾸기
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";       // 3 4 5
    cout << endl;

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";       // 1 2
    cout << endl;
    return 0;
}