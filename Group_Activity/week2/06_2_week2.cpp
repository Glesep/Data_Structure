#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str("There are two needles with needles.");
    string str2("needle");

    size_t found = str.find(str2);      // 14
    if (found != string::npos)
        cout << found << '\n';

    found = str.find("needles are small", found + 1, 6);    // 27   -   str에서 found+1인덱스 요소부터 needles are small의 앞 6글자 찾기
    if (found != string::npos)
        cout << found << '\n';

    str.replace(str.find(str2), str2.length(),
                "preposition");                 // There are two prepositions with needles.
    cout << str << '\n';
    return 0;
}