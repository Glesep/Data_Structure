#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {8, 4, 5, 9};
    v.push_back(6);         // 8 4 5 9 6
    v.push_back(9);         // 8 4 5 9 6 9
    v[2] = -1;              // 8 4 -1 9 6 9

    for (int n : v)
        std::cout << n << ' ';
    std::cout << '\n';
}