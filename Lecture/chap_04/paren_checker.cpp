#include <iostream>
#include <string>
using namespace std;
const int MAX_LENGTH = 100;
// 스택이 구현되었다고 가정한다.


string OPEN = "([{";
string CLOSE = ")]}";
string::size_type is_open(char ch)
{
    return OPEN.find(ch);
}
string::size_type is_close(char ch)
{
    return CLOSE.find(ch);
}

int main()
{
    string expr;
    getline(cin, expr);
    if (is_balanced(expr))
        cout << "balanced." << endl;
    else
        cout << "unbalanced." << endl;
}

bool is_balanced(string expr)
{
    for (char ch : expr)
    {
        if (is_open(ch) != string::npos)
            push(ch);
        else if (is_close(ch) != string::npos)
        {
            if (empty())
                return false;
            char top_ch = top();
            pop();
            if (is_open(top_ch) != is_close(ch))
                return false;
        }
    }
    return empty();
}