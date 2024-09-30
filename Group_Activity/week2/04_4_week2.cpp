#include <iostream>
#include <string>
int main()
{
    std::string name("John");
    std::string family("Smith");
    name += " K. ";     // John K.
    name += family;     // John K. Smith
    name += '\n';       // John K. Smith\n

    std::cout << name;
    return 0;
}