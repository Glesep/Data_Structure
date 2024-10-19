#include <iostream>
#include <list>
bool mycomparison(double first, double second)
{
    return (int(first) < int(second));
}

int main()
{
    std::list<double> first, second;
    first.push_back(3.1);
    first.push_back(2.2);
    first.push_back(2.9);
    second.push_back(3.7);
    second.push_back(7.1);
    second.push_back(1.4);

    first.sort();
    second.sort();

    first.merge(second);
    second.push_back(2.1);
    first.merge(second, mycomparison);      // 조건에서 둘이 동일하면 second쪽이 뒤

    for (auto it = first.begin(); it != first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}