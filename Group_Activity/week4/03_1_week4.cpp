#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.assign(5, 10);                // 10을 5번 반복해서 v에 넣는다.
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";        // 10 10 10 10 10

    v.push_back(15);                // 10 10 10 10 10 15
    int n = v.size();               // 6
    cout << "The last element is: " << v[n - 1] << endl;    // 15
    v.pop_back();                   // 10 10 10 10 10

    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";        // 10 10 10 10 10
    cout << endl;

    v.insert(v.begin(), 5);         // v.begin()에 5 삽입, 5 10 10 10 10 10
    cout << "The first element is: " << v[0] << endl;       // 5

    v.erase(v.begin());             // v.begin()에 있는 요소 삭제, 나머지 위치 앞으로 한칸씩 조정
    cout << "The first element is: " << v[0] << endl;       // 10

    v.clear();                      // 모든 요소 삭제, capacitiy는 유지
    cout << "Vector size: " << v.size() << endl;    // 0
    cout << "Vector Capacity: " << v.capacity() << endl;

    return 0;
}