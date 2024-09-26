#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point2D;

int main() {
    int *arr = (int *)malloc(16);                   // 4/4/4/4
    arr[0] = 1, arr[1] = 2, arr[2] = 3, arr[3] = 4;

    Point2D *ptr_point = (Point2D *) malloc(16);    // 8/8
    ptr_point->x = 10, ptr_point->y = 20;

    free(arr);
    free(ptr_point);

    return 0;
}