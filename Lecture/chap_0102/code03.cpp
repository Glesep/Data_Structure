#include <iostream>
    
using namespace std;

class Point2D {
public:
    int x, y;
};

int main() {
    Point2D p;
    p.x = 1, p.y = 2;

    Point2D *ptr_p = &p;

    (*ptr_p).x = 10;
    ptr_p->y = 20;          // == (*ptr_p).y

    cout << ptr_p->x << " " << ptr_p->y << endl;

    
    return 0;
}
