#include <iostream>
#include <vector>
using namespace std;
/*
front() -   벡터의 맨 첫 요소 가져오기
back()  -   벡터의 맨 마지막 요소 가져오기

*/
int main()
{
    vector<int> g1;
    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);       // 10 20 30 40 50 60 70 80 90 100

    cout << "g1[2] = " << g1[2] << endl;    // 30
    cout << "g1.at(4) = " << g1.at(4) << endl;  // 50
    cout << "g1.front() = " << g1.front() << endl;  // 10
    cout << "g1.back() = " << g1.back() << endl;    // 100
    return 0;
}