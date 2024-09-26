#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *p = (int *) malloc(n*sizeof(int));     // malloc 함수의 매개변수로 할당받을 메모리의 크기를 byte 단위로 지정한다. malloc이 반환하는 주소는 void * 타입이므로 원하는 타입으로 변환해주어야 한다.

    p[0] = 12;
    p[1] = 24;
    *(p+2) = 36;        // == p[2]

    printf("%d", p[2]);

    free(p);                                    // == delete



    return 0;
}