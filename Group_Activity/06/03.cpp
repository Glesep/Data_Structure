#include <iostream>
    
using namespace std;

void func3(int n);

int main()
{
    func3(4);
    
    return 0;
}

void func3(int n) {
    if (n==0)
        return;
    func3(n/2);
    printf("%d", n%2);
}
