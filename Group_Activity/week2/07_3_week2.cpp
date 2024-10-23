// compare() usage: cplusplus.com/reference/string/string/compare


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 ("green apple");
    string str2 ("red apple");

    if (str1.compare(str2) != 0)                            // str1과 str2가 같지 않다면
        cout << str1 << " is not " << str2 << '\n';

    if (str1.compare(6,5,"apple") == 0)                     // str1의 인덱스 6부터 5개의 단어가 apple과 같다면
        cout << "still, " << str1 << " is an apple\n";

    if (str2.compare(str2.size()-5, 5, "apple") == 0)       // str2의 인덱스 str2.size()-5부터 5개의 단어가 apple과 같다면
        cout << "and " << str2 << " is also an apple\n";

    if(str1.compare(6, 5, str2, 4, 5) == 0)                 // str1의 인덱스 6부터 5개의 단어와 str2의 인덱스 4부터 5개의 단어가 같다면
        cout << "therefore, both are apples\n";

    return 0;
}
