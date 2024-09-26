#include <stdio.h>
#include <string.h>
#define MAXWORDS 100
#define MAXLEN 30

int main() {
    char *words[MAXWORDS];
    int n;
    scanf("%d", &n);

    char buf[MAXLEN];
    for (int i=0; i<n; i++) {
        scanf("%s", buf);

        // strdup(): 매개변수로 받은 하나의 문자열을 복제해서 반환한다. 
        // 복제하는 과정에서 동적 메모리 할당이 일어나기 때문에(malloc), strdup을 사용 후 garbage를 없애기 위해 free를 시켜주어야만 한다.
        words[i] = strdup(buf);

        /*
        common mistakes
        1. scanf("%s", words[i]);
        2. words[i] = buf;
        3. strcpy(sords[i], buf);
         */
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}