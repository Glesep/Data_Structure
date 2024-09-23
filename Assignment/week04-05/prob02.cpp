#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> numbers;

    for (int i = 2; i < n+1; i++)   //vector에 2에서 n까지의 양의 정수를 저장
        numbers.push_back(i);

    for (auto it = numbers.begin(); it < numbers.end(); it++) {
        for (auto it2 = it+1; it2 < numbers.end(); it2++) {
            if (*it2 % *it == 0) {
                it2 = numbers.erase(it2);
                it2--;
            }
        }
    }

    for (auto it = numbers.begin(); it < numbers.end(); it++)
        cout << *it << endl;


    return 0;
}
