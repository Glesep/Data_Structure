#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    

    // fgets(문자 배열, 문자 배열의 크기, 입력될 내용을 지닐 매체(파일, 키보드 등)): 라인 단위로 입력받는 함수, 파일의 끝에 도달하면 NULL을 return한다.
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        /*
        fgets는 각 라인의 끝에 있는 '\n'까지 읽어준다. ('\n'까지 한 줄에 추가되어 길이가 1 늘어난다.)
        만약 이 문자가 필요없다면 '\n'을 문자열의 끝을 표시하는 '\0'로 변경한다.
        */
        if (buffer[strlen(buffer)-1] == '\n')              
            buffer[strlen(buffer)-1] = '\0';

        printf("%s:%d\n", buffer, strlen(buffer));
    }

    return 0;
}