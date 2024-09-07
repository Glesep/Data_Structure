#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line))                              // getline(cin, line, '\n')과 동일, 지정한 문자의 앞까지 읽어 주는 함수
        cout << line << ":" << line.length() << endl;
    
    return 0;
}
