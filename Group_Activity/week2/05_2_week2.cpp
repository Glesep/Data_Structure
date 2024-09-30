#include <iostream>
#include <string>
/*
str.erase()- 실행하면 결과값 str에 저장
https://cplusplus.com/reference/string/string/erase/
*/
int main()
{
    std::string str("This is an example sentence.");
    std::cout << str << '\n';       

    str.erase(10, 8);   // This is an sentence. 시작 인덱스의 요소 포함 8개 삭제
    std::cout << str << '\n';

    str.erase(str.begin() + 9); // This is a sentence.  가리키는 iterator의 요소 삭제
    std::cout << str << '\n';

    str.erase(str.begin() + 5, str.end() - 9);  // This sentence. iterator에서 iterator까지.
    std::cout << str << '\n';

    return 0;
}