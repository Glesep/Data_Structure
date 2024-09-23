#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
unique() 함수
cplusplus.com/reference/algorithm/unique/
https://velog.io/@whipbaek/c-unique-%ED%95%A8%EC%88%98%EC%97%90-%EA%B4%80%ED%95%98%EC%97%AC

1,1,3,4,4,5,6,6,6
1,3,4,5,6,5,6,6,6
*/
int main()
{
    vector<int> my_vec = { 1, 3, 1, 4, 4, 6, 5, 6, 6};
    sort(my_vec.begin(), my_vec.end());     

    for (int item : my_vec)                  // 1,1,3,4,4,5,6,6,6
        cout << item << " ";
    cout << endl;

    auto it = unique(my_vec.begin(), my_vec.end()); // 1,3,4,5,6,5,6,6,6   it은 두번째 5를 가리킴, 
    for (int item : my_vec)                 
        cout << item << " ";
    cout << endl;

    my_vec.erase(it, my_vec.end());         // 1,1
    for (int item : my_vec)
        cout << item << " ";
    cout << endl;
    return 0;
    
    return 0;
}
