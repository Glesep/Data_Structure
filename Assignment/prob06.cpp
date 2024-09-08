#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int countWords(string line);

int main()
{
    string input;

    while (1)
    { // getline(cin, line, '\n')과 동일, 지정한 문자의 앞까지 읽어 주는 함수
        cout << "$ ";
        getline(cin, input);

        if (input == "exit")
            break;

        int wordCount = countWords(input);

        cout << input << ":" << input.length() << ":" << wordCount << endl;
    }

    return 0;
}

/**
 * @brief string 변수 내의 단어 개수를 반환하는 함수
 *
 * @param line 대상 string 변수
 * @return int 단어 개수
 */
int countWords(string line)
{

    int count = 0;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, ' ')) // 구분자 기준으로 잘라 읽기
        if (str != "")                 // 공백이 여러 개일 때 아무것도 읽어오지 못하는 경우를 제외
            count++;

    return count;
}
