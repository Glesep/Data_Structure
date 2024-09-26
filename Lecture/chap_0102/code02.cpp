// 25:06

#include <iostream>
using namespace std;

void swap(int *x, int *y);
void swap_error(int x, int y);

int main() {
    int a = 1, b = 2;
    swap_error(a, b);
    swap(a, b);
    cout << a << " " << b << endl;
}

/**
* @brief 
* 이 함수는 값에 의한 호출을 이해하기 위한 예시입니다.
* 이 함수를 사용해도 변수 사이의 값의 교환이 일어나지 않습니다.
*
* @param x 값을 바꾸고 싶은 변수
* @param y 값을 바꾸고 싶은 변수
*/
void swap_error(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
    
    cout << x << " " << y << endl;
}

/**
 * @brief 
 * 이 함수는 포인터를 이용하여 변수 간의 값의 교환을 해주는 함수입니다.
 * 
 * @param x 값을 바꾸고 싶은 변수
 * @param y 값을 바꾸고 싶은 변수
 */
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}