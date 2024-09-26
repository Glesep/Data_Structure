// Iterator의 사용

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i < 4; i++)
        v.push_back(i + 1);

    vector<int>::iterator it;
    it = v.begin();

    // iterator의 증가
    it++;

    // iterator를 이용한 원소 읽기/쓰기
    int n = *it;       // n=2
    cout << n << endl; // will print 2

    *it = n * 2;       // n=4
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // 원소 삽입
    v.insert(it, 100);      // insert() 사용 시 it는 invalid해짐.
    for (int x : v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl; // it는 invalid해짐. 따라서 무의미한 값이 출력
    
    it = v.begin();
    it += 2; // 두 칸 전진
    it = v.insert(it, 200); // insert()는 값 삽입 후 현재 iterator의 위치를 반환한다.
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl;

    // 원소 삭제
    it = v.begin();
    it += 3; // 3칸 전진
    it = v.erase(it);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl; // it는 erase된 원소의 다음 위치를 가리킴. 따라서 3을 출력

    return 0;
}