#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &str, int start, int end)
{
    // 기저 조건: 문자열의 중앙까지 검사했거나, 한 글자만 남은 경우
    if (start >= end)
    {
        return true;
    }

    // 양 끝의 문자가 다르면 회문이 아님
    if (str[start] != str[end])
    {
        return false;
    }

    // 다음 문자쌍 검사를 위해 재귀 호출
    return is_palindrome(str, start + 1, end - 1);
}

int main()
{
    string word;
    cout << "단어를 입력하세요: ";
    cin >> word;

    if (is_palindrome(word, 0, word.length() - 1))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
