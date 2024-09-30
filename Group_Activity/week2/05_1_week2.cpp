#include <iostream>
#include <string>
int main()
{
    std::string str = "to be question";
    std::string str2 = "the ";
    str.insert(6, str2);        // to be the question   문자열 인덱스 6 위치에 삽입 (원래 있던 문자열은 뒤로 밀림)

    std::cout << str << '\n';
    return 0;
}