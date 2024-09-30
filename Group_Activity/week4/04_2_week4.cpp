#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 3, 4, 5};
    int k = 3;
    auto it = find(v.begin(), v.end(), k);  // 벡터의 처음부터 끝까지 k와 같은지 검사, 처음 찾아진 이터레이터 반환
    if (it != v.end())
        v.erase(it);    // 1 2 3 4 5

    for (auto element : v)
        cout << element << " ";
    cout << endl;
    return 0;
}