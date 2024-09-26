#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello";
    char str2[] = "world!";


    // strlen(): 문자열의 길이 계산
    printf("%d\n", strlen(str1));
    printf("%d\n", strlen(str2));

    char str3[20];
    // strcpy(): 두번째 문자열을 첫번째 문자배열에 복사 (그냥 포인터 변수를 첫 번째 변수로 넣는 것에 주의!) 
    strcpy(str3, str1);
    printf("%s\n", str3);

    // strcat(): 두번쨰 문자열을 첫번째 문자열에 합해준다.
    strcat(str3, str2);
    printf("%s\n", str3);

    // strcmp(): 두 문자열을 비교하여 첫 번쩨가 사전식 순서로 앞서면 음수, 나중이면 양수, 동일하면 0을 반환한다. (부등호를 생각하자)
    int result = strcmp(str1, str2);
    printf("%d\n", result);

    char str4[] = "hello";
    result = strcmp(str1, str4);
    printf("%d\n", result);


    return 0;
}
