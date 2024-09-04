#include <stdio.h>
#include <stdlib.h>

// 배열 재할당 (array reallocation)

int main() {
    int *array = (int *)malloc(4*sizeof(int));

    /* 배열 array의 크기가 부족할 떄 */
    int *tmp = (int *)malloc(8*sizeof(int));        // 전의 크기의 2배로 크기 설정

    for (int i=0; i<4; i++)
        tmp[i] = array[i];
    
    free(array);                                    // 기존의 배열이 있는 메모리를 삭제
    array = tmp;
}

/*
배열 재할당은 처음에 동적메모리 할당으로 생성한 배열에 대해서만 가능하다.
예를 들어 아래와 같이 할 수 없다.

    int array[10];                      정적 생성한 배열
    int *tmp = (int *) malloc(20);
    array = tmp                         array는 int *const타입이므로 수정 불가


*/