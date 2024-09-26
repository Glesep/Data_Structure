#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, str3;

    cin >> str1 >> str2;

    str3 = str1;                                    // string 복사
    cout << "str3 : " << str3 << endl;

    str3 = str1 + " " + str2;                       // string 합치기
    cout << "str1 + str2 : " << str3 << endl;

    int len = str3.length();                        // string 길이 구하기
    cout << "str3.length() : " << len << endl;

    string str4 = "hello";
    if (str1 == str4)
        cout << "Same" << endl;
    else if (str1 < str4)
        cout << "str1 first" << endl;
    else
        cout << "str4 first" << endl;



    return 0;
}