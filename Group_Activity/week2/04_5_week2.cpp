#include <iostream>
#include <string>

/*
str.append()
https://cplusplus.com/reference/string/string/append/
*/
int main()
{
    std::string str;
    std::string str2 = "Writing ";
    std::string str3 = "print 10 and then 5 more";

    str.append(str2);       // Writing 
    str.append(str3, 6, 3); // Writing 10 
    str.append("dots are cool", 6); // Writing 10 dots

    std::cout << str << '\n';
    return 0;
}