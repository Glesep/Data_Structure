#include <iostream>
#include <string>
using namespace std;

template <typename T>
int compare(T v1, T v2)
{
    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;

    return 0;
}

int main()
{
    cout << compare<int>(1, 0);

    cout << compare<string>("hello", "world");
    return 0;
}
