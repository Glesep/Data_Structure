#include <iostream>
using namespace std;

int main() {

    // 포인터 변수는 일반적으로 8바이트의 크기를 가진다.(타입의 기존 크기와는 별개)
    cout << sizeof(int) << " " << sizeof(int *) << endl;
    cout << sizeof(char) << " " << sizeof(char *) << endl;
    cout << sizeof(double) << " " << sizeof(double *) << endl;

    // ===================================================================

    


    return 0;
}