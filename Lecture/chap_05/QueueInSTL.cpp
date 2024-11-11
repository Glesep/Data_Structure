#include <iostream>
#include <queue>
using namespace std;
void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout << q1.size();
    cout << q1.front();
    queue<int> q2(q1);
    q2.pop();
    print_queue(q1);
    print_queue(q2);
    return 0;
}