#include <iostream>
#include <string>
using namespace std;

int main() {
    // string 타입 변수를 생성, 초기화하는 법


    string s0;

    string s1("hello");
    string s2 = "hello";
    string s3 = string("hello");
    string s4{"hello"};
    string s5 = {"hello"};
    
    string s6 = s5;
    string s7(s5);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    
    
    
    return 0;
}
