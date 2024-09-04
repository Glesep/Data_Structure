#include <iostream>
using namespace std;

class Point2D {
public:
    double x, y;
};

int main() {
    Point2D *ptr_p = new Point2D;
    ptr_p->x = 1;
    ptr_p->y = 2;

    cout << ptr_p->x << " " << ptr_p->y << endl;

    delete ptr_p;
    

    // ===========================================

    int n;
    cin >> n;
    int *p = new int [n];           // malloc과 달리 byte 단위가 아니라 배열의 크기를 지정, 배열의 첫 칸의 주소를 반환함

    p[0] = 12;
    p[1] = 24;
    *(p+2) = 36;

    delete [] p;


    return 0;
}
