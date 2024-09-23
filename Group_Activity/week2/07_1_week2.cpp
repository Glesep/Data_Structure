#include <iostream>
#include <string>
using namespace std;

int main() {
    string str ("Please, replace the vowels in this sentence by asterisks.");

    size_t found = str.find_first_of("aeiou");  // str 내에서 aeiou 가 제일 먼저 나오는 인덱스를 반환
    while(found!=string::npos) {                // string의 끝이 될 때까지 반복
        str[found]='*';                         // *로 바꾼다.
        found=str.find_first_of("aeiou", found+1);  // found+1 인덱스부터 찾는다.
    }

    cout << str << '\n';
    
    return 0;
}
