#include <stdio.h>
#include <string.h>
#define MAXWORDS 100
#define MAXLEN 30

int main()
{
    char *words[MAXWORDS];
    int n;
    scanf("%d", &n);
    char buf[MAXLEN];

    for (int i = 0; i < n; i++) {
        /* 
        방법1:
            오답: words 변수는 포인터를 담는 배열이기 때문에 words 배열의 요소에 문자열이 들어갈 수 없다.
            words[i]에는 메모리 주소가 정의되지 않았기 때문에 들어가지 못한다. (칸만 정의되어있음, 직접적인 주소가 없다.)
        */
        scanf("%s", words[i]);  // scanf에는 전달할 대상의 주소를 알려줘야함


        /*
        방법2:
            buf는 하나의 고정된 배열이다. 따라서 words 배열의 각 요소에는 buf 배열의 주소가 동일하게 들어간다.
            따라서 buf 문자열에 마지막에 넣은 값이 동일하게 출력되어 기존 의도와는 다르게 동작한다.
        */
        scanf("%s", buf);
        words[i] = buf;


        /*
        방법3:
            strcpy 함수는 첫번째 매개변수에 있는 배열에 두번째 문자열의 요소들을 복사하는 함수이다.
            words 배열은 char타입 포인터를 담는 배열이므로 문자열을 담을 수 없다.
            words[i] 자리에 충분한 크기를 가진 버퍼를 할당받은 char타입 포인터가 존재하면 받을 수 있다.
            ex
        */ 
        scanf("%s", buf);
        strcpy(words[i], buf);

        // ======================================================================================

        /*
        올바른 방법:
            strdup 함수를 이용하여 각 반복마다 입력받은 문자열에 대한 메모리 할당을 따로 시켜준다.
            이로써 words 배열의 각 요소가 다른 배열의 주소를 가리키게 되어 방법2의 문제를 해결할 수 있다.
        */
        scanf("%s", buf);
        words[i] = strdup(buf);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        free(words[i]);                             // strdup으로 동적 생성된 배열을 더 이상 사용하지 않으므로 free로 처리한다.
    }

    return 0;
}