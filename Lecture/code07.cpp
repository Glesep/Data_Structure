#include <iostream>
    
using namespace std;

class Point2D {
public:
    double x, y;
};


int main() {
    Point2D points[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    Point2D center = computeCenter(points, n);
    
    return 0;
}

Point2D computeCenter(Point2D *pts, int k) {
    Point2D c;
    for (int i=0; i<k; i++) {
        c.x += (*(pts+i)).x;            // c.x += pts[i].x; 와 동일
        c.y += (pts+i)->y;              // c.y += pts[i].y; 와 동일

    }
    c.x /= k;
    c.y /= k;

    return c;
}
