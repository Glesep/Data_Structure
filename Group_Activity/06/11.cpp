#include <iostream>
#include <string>
using namespace std;

int compare(string str1, string str2, size_t index = 0)
{
    // 두 문자열 중 하나가 끝났을 경우
    if (index == str1.length() || index == str2.length())
    {
        if (str1.length() < str2.length())
            return -1;
        if (str1.length() > str2.length())
            return 1;
        return 0;
    }

    // 현재 위치의 문자 비교
    if (str1[index] < str2[index])
        return -1;
    if (str1[index] > str2[index])
        return 1;

    // 현재 문자가 같으면 다음 문자 비교
    return compare(str1, str2, index + 1);
}

int main()
{
    string word1, word2;
    cout << "첫 번째 단어를 입력하세요: ";
    cin >> word1;
    cout << "두 번째 단어를 입력하세요: ";
    cin >> word2;

    int result = compare(word1, word2);

    if (result < 0)
    {
        cout << word1 << " " << word2 << endl;
    }
    else if (result > 0)
    {
        cout << word2 << " " << word1 << endl;
    }
    else
    {
        cout << "두 단어가 같습니다: " << word1 << endl;
    }

    return 0;
}
