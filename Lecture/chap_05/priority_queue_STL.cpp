#include <iostream>
#include <queue>
using namespace std;
// (1) 최대 우선순위 큐
// int main()
// {
//     int arr[6] = {10, 2, 4, 8, 6, 9};
//     priority_queue<int> pq;
//     for (int i = 0; i < 6; i++)
//         pq.push(arr[i]);
//     while (!pq.empty())
//     {
//         cout << pq.top() << ' ';
//         pq.pop();
//     }
//     return 0;
// }

void showpq(priority_queue<int, vector<int>, greater<int>> g)
{
    while (!g.empty())
    {
        cout << ' ' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main()
{
    int arr[6] = {10, 2, 4, 8, 6, 9};
    // <데이터 타입, 거쳐갈 자료구조, greater 클래스(Function object 클래스 - 함수처럼 class 사용)
    priority_queue<int, vector<int>, greater<int>> gquiz(arr, arr + 6);
    cout << "Priority Queue : ";
    showpq(gquiz);
    return 0;
}