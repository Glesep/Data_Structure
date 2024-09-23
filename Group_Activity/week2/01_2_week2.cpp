#include <iostream>

using namespace std;

int main()
{
    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;

    p1 = &firstvalue;
    p2 = &secondvalue;

    *p1 = 10;                   // fisrtvalue == 10
    *p2 = *p1;                  // secondvalue == 10

    p1 = p2;                    // p1 == &secondvalue
    *p1 = 20;                   // secondvalue == 20

    cout << "firstvalue is " << firstvalue << '\n';     // 10
    cout << "secondvalue is " << secondvalue << '\n';   // 20
    return 0;
}
