
#include <iostream>
#include <vector>
using namespace std;
/*
std::rbegin 은 마지막 원소 주소를, std::rend 는 처음 원소의 1칸 이전 주소를 가리키는 reverse_iterator를 만들어 반환
*/
int main()
{
    vector<int> g1;
    for (int i = 1; i <= 5; i++)    // 1 2 3 4 5
        g1.push_back(i);

    for (auto i = g1.begin(); i != g1.end(); ++i)   // 1 2 3 4 5
        cout << *i << " ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)  // 5 4 3 2 1
        cout << *ir << " ";

    return 0;
}