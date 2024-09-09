#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int operation(int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return (g);
}

int main()
{
    int m, n;
    int (*minus)(int, int) = subtraction;   // 함수 포인터

    m = operation(7, 5, addition);      // 12
    n = operation(20, m, minus);        // 8

    cout << n;                          // 8
    return 0;
}