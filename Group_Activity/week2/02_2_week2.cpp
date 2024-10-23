#include <iostream>

using namespace std;

void increment_all(int *start, int *stop)
{
    int *current = start;
    while (current != stop)
    {
        ++(*current);
        ++current;
    }
}

/*
    const int * : const int 를 가리키는 포인터
                포인터의 값은 변경 가능하지만 포인터가 가리키는 값은 const int 타입이므로 변경 불가
    
    int* const : const 포인터가 int 타입을 가리킴, 포인터의 값은 변경 불가능, 포인터가 가리키는 값은 변경 가능

 */

void print_all(const int *start, const int *stop)
{
    const int *current = start;
    while (current != stop)
    {
        cout << *current << '\n';
        ++current;
    }
}

int main()
{
    int numbers[] = {10, 20, 30};
    increment_all(numbers, numbers + 3);
    print_all(numbers, numbers + 3);        // 11 21 31
    return 0;
}
