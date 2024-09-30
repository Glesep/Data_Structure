#include <iostream>
#include <string>

int main()
{
    std::string str("Test string");
    for (unsigned i = 0; i < str.length(); ++i)     // unsigned만 적혀있으면 unsigned int
        std::cout << str.at(i);
    return 0;
}
