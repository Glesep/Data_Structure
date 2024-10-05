#include <stdio.h>
#include <string.h>

/*
strtok는 2개 이상의 연속된 delimiter를 하나의 delimiter로 인식
*/
int main()
{
    char str[] = " study hard, or sleep. ";
    char delim[] = " ";
    char *token;
    token = strtok(str, delim);
    while (token != NULL)
    {
        printf("next token is: %s:%d\n", token, strlen(token));
        token = strtok(NULL, delim);
    }
    return 0;
}