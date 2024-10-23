#include <iostream>
using namespace std;

void increase(void *data, int psize)        // void *data는 포인터 타입을 정하지 않은 것
{
    if (psize == sizeof(char))      
    {
        char *pchar;
        pchar = (char *)data;
        ++(*pchar);                     // x의 아스키코드에 +1 해주면 y의 아스키코드
    }

    else if (psize == sizeof(int))
    {
        int *pint;
        pint = (int *)data;
        ++(*pint);
    }
}

int main()
{
    char a = 'x';
    int b = 1602;

    increase(&a, sizeof(a));
    increase(&b, sizeof(b));

    cout << a << ", " << b << '\n';     // y, 1603

    return 0;
}