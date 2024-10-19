#include <iostream>
#include <list>
int main()
{
    std::list<int> mylist;
    for (int i = 1; i < 10; ++i)
        mylist.push_back(i);

    mylist.reverse();   // 순서를 역으로 바꿈
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}