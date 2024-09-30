#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    string str("Please split this sentence into tokens");
    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());      // str을 c-style strring으로 바꾼 후 cstr에 복사
    char *p = std::strtok(cstr, " ");   // strtok로 tokenizing
    while (p != 0)
    {
        cout << p << '\n';
        p = std::strtok(NULL, " ");
    }
    delete[] cstr;
    return 0;
}