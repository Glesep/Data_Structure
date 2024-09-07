#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// 2. 사전식 순서 정렬

string trim(string str);

int main()
{
    ifstream infile("input4.txt");

    string word;          // 한 단어를 받는 변수 정의
    string words[1000];   // 단어들을 저장하는 변수 정의
    int word_count[1000]; // 단어의 등장 빈도를 체크하는 배열
    int words_index = 0;  // words 배열의 최고 인덱스

    while (infile)
    {

        int index = 0;
        infile >> word;

        word = trim(word);

        if (word.length() < 2) // 길이가 2 이상이 아닐 떄 다음 반복으로 넘어감
            continue;

        for (; index <= words_index; index++)
        {
            if (words[index] == word)
            { // 단어가 같을 시, 반복 종료
                break;
            }
        }

        if (index - 1 != words_index)
        { // 단어가 같을 시(index != words_index-1), 등장횟수를 1 올리고 다음 반복으로 넘어감
            word_count[index]++;
            continue;
        }

        words[words_index] = word; // 중복되지 않은 word를 words 배열에 추가

        if (infile.eof() == false) // 파일의 끝이 아닐 때에만 words_index를 추가
            words_index++;
    }

    infile.close();

    // bubble sort
    for (int i = words_index; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (words[j] > words[j + 1])
            {
                swap(words[j], words[j + 1]);
                swap(word_count[j], word_count[j + 1]);
            }
        }
    }

    for (int i = 0; i <= words_index; i++)
    {
        cout << words[i] << " " << word_count[i] + 1; // 출력되는 모든 단어는 한번씩 나오므로 word_count[i]+1 출력
        if (i != words_index)
            cout << endl;
    }

    return 0;
}

/**
 * @brief 각 단어의 앞뒤에 붙은 특수문자와 숫자를 제거하는 함수
 *
 * @param str 함수를 적용하고 싶은 문자열
 * @return string 함수 적용 후 문자열
 */
string trim(string str)
{
    int s = 0, t = str.length() - 1;

    while (s < str.length() && !isalpha(str[s]))
        s++;
    while (t >= 0 && !isalpha(str[t]))
        t--;
    if (s <= t)
        return str.substr(s, t - s + 1);            // s를 처음부터 t-s+1개만큼 자름
    else
        return "";                                  // 전부 잘렸으면 공백 반환
}
