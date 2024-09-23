#include <iostream>
using namespace std;

typedef int (*myfunc)(int, int);        // function pointer 정의 가능

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int operation(int x, int y, myfunc functocall)
{
    int g;
    g = functocall(x, y);
    return (g);
}

int main()
{
    int m, n;
    //int (*minus)(int, int) = subtraction;   // 함수 포인터

    myfunc minus = subtraction;
    m = operation(7, 5, addition);      // 12
    n = operation(20, m, minus);        // 8

    cout << m << endl;
    cout << n << endl;                  // 8
    return 0;
}