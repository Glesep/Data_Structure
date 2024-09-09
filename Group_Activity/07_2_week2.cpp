#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "We think in generalities, but we live in details.";
    string str2 = str.substr(3, 5);
    size_t pos = str.find("live");
    string str3 = str.substr(pos);          // 인덱스만 들어있으면 인덱스 이후 문자열의 끝까지 자름
    cout << str2 << ' ' << str3 << '\n';
    
    return 0;
}
