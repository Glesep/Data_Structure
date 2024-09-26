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
    while (getline(sstream, str, delimiter))    // delimeter 전에 있는 문자열을 잘라낸다. 두 delimeter이 연속으로 있을 경우 공백문자열으로 tokenizing한다.
        tokens.push_back(str);
    return tokens;
}