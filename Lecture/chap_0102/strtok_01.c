#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "now # is the time # to start preparing ### for the exam#";
    // delimiter는 하나의 문자가 아니라 C-string
    char delim[] = "#";
    char *token;
    token = strtok(str, delim);     // 첫 번재 호출


    // 이어지는 호출들
    while (token != NULL)
    {
        printf("next token is: %s:%d\n", token, strlen(token));
        token = strtok(NULL, delim);
    }
    
    return 0;
}