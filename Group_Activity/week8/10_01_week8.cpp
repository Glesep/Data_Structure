#include <iostream>
#include <list>
#include <string>
#include <cctype>
using namespace std;
bool compare_nocase(const string &first,
                    const string &second)
{
    unsigned int i = 0;
    while (i < first.length() && i < second.length())
    {
        if (tolower(first[i]) < tolower(second[i]))
            return true;
        else if (tolower(first[i]) > tolower(second[i]))
            return false;
        ++i;
    }
    return first.length() < second.length();
}
int main()
{
    list<string> mylist;
    list<string>::iterator it;

    mylist.push_back("one");
    mylist.push_back("two");
    mylist.push_back("Three");
    mylist.sort();

    for (it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    mylist.sort(compare_nocase);    // 조건에서 true의 조건대로 sort

    for (it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}