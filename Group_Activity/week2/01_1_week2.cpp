#include <iostream>
    
using namespace std;

int main()
{
    int firstvalue, secondvalue;
    int *mypointer;

    mypointer = &firstvalue;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;

    cout << "firstvalue is " << firstvalue << '\n';     // 10
    cout << "secondvalue is " << secondvalue << '\n';    // 20
    
    return 0;
}
