#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto i = v.begin();i != v.end(); i++) {        // for문에 전위/후위는 결과적으로 똑같음 - for문 진입 시, +1한 상태로 진입
        if(*i % 2 == 0) {
            i = v.erase(i);
            i--;
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;
    
    return 0;
}
