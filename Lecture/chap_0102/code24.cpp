// c++ tokenizing


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << line << ":" << line.length() << endl;
        vector<string> tokens = split_line(line, ' ');
        for (string str : tokens)
            cout << str << endl;
    }
    return 0;
}
vector<string> split_line(string &line, char delimiter)
{
    vector<string> tokens;
    stringstream sstream(line);
    string str;

    /*
    delimeter 전에 있는 문자열을 잘라낸다. 바로 공백문자가 나왔을 경우 전은 아무것도 없는 빈 문자열이므로 빈 문자열이 tokenizing
    ex) "__hello world__"를 " "로 tokenizing    (_ == " ")
        0. ""
        1. ""
        2. hello
        3. world
        4. ""
    */
    while (getline(sstream, str, delimiter))    
        tokens.push_back(str);
    return tokens;
}