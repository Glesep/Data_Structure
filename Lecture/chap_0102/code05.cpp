#include <iostream>
    
using namespace std;

int main() {
    // 포인터의 타입이 차지하는 bit크기에 따라서 포인터 산수를 했을 때 적용되는 값이 달라짐
    char c = 'h';
    char *ptrc = &c;
    cout << "Char address" << endl;
    cout << (void *)ptrc << endl;
    cout << (void *)(ptrc+1) << endl;
    cout << (void *)(ptrc-1) << endl;
    cout << "===============================" << endl;

    int x = 10;
    int *ptrint = &x;
    cout << "Int address" << endl;
    cout << ptrint << endl;         
    cout << ptrint+1 << endl;           // 정수형 포인터, 1을 더하면 다음 정수로 넘어가라는 뜻으로 다음 정수로 넘어가기 위해 주소에 4가 더해짐
    cout << ptrint-1 << endl;           // 정수형 포인터, 1을 빼면 다음 정수로 넘어가라는 뜻으로 다음 정수로 넘어가기 위해 주소에 4가 빼짐

    return 0;
}
