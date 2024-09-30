#include <iostream>
#include <string>
using namespace std;
/*
str.replace()
https://cplusplus.com/reference/string/string/replace/
*/
int main()
{
    string str = "this is a test string.";
    string str2 = "n example";
    string str3 = "sample phrase";

    str.replace(9, 5, str2);    // this is an example string. - 9번째 인덱스 요소부터 5개까지를 str2로 대체
    cout << str << '\n';

    str.replace(str.begin(), str.end() - 3, str3);  // sample phraseng  -   str.begin 부터 str.end-3까지를 str3으로 대체
    cout << str << '\n';
    return 0;
}