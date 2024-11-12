#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
void pop_println(T &pq)
{
    for (; !pq.empty(); pq.pop())
        cout << pq.top() << ' ';
    cout << '\n';
}
int main()
{
    vector<string> data = {"animal", "drop", "and", "for", "bold", "clue"};

    struct Compare
    {
        bool operator()(const string l, const string r) const
        {
            return l.length() > r.length() || l.length() == r.length() && l > r;
        }
    };

    // compare func을 내가 정의해서 삽입
    priority_queue<string, vector<string>, Compare> custom_priority_queue;

    for (auto s : data)
        custom_priority_queue.push(s);

    pop_println(custom_priority_queue);

    // 람다 함수 - anonymous function

    auto cmp = [](/*매개변수*/int left, int right) 
    { /*함수의 body - XOR하는 함수(맨 마지막 비트 반전)*/return (left ^ 1) < (right ^ 1); };
    
    // decltype - 객체의 타입명을 리턴해주는 함수
    priority_queue<int, vector<int>, decltype(cmp)> lambda_priority_queue(/*함수이름 넣기*/cmp);
    vector<int> nums = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n : nums)
        lambda_priority_queue.push(n);
    pop_println(lambda_priority_queue);
}