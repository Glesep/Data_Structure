#include <iostream>
#include <string>
int main()
{
    std::string str("hello world!");
    str.pop_back();         // hello world  -   맨 뒤의 요소 삭제
    std::cout << str << '\n';
    return 0;
}