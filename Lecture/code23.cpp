#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec{10, 8, 1, 5, 4, 6, 11, 2};
    vector<int>::iterator it = vec.begin();     // iterator 사용
    while (it != vec.end())                     // it.end()는 마지막 원소의 다음 위치를 가리키므로 이렇게 되면 얻떤 원소도 빼먹지 않는다.
    {
        if (*it % 2 == 0)
        {
            *it *= 2;
            it++;
        }
        else
            it = vec.erase(it);                 // it은 삭제된 다음 원소를 가리킨다. (삭제된 요소의 뒷요소)
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}