#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    vector<int>::iterator it1, it2;
    it1 = v.begin();
    it2 = v.end();
    it2--;
    it2--;

    v.erase(it1, it2);      // it1부터 it2 이전까지 해당하는 요소들 삭제
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
    
    return 0;
}