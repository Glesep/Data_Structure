#include <stack>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    stack<char> dsc1;       // default로는 deque (double-ended queue)를 이용하여 stack 구현

    // 이런 식으로 사용할 컨테이너 타입을 지정할 수 있다.
    
    stack<char, deque<char>> dsc2;

    stack<int, vector<int>> vsi1;

    stack<int, list<int>> lsi;

    vector<int> v1{1};

    stack<int, vector<int>> vsi2(v1);
    cout << "The element at the top of stack vsi2 is "
         << vsi2.top() << "." << endl;
}