#include <iostream>
#include <list>
using namespace std;
bool single_digit(const int &value)
{
    return (value < 10);
}

bool is_odd(const int &value)
{
    return (value % 2) == 1;
}

int main()
{
    int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
    list<int> mylist(myints, myints + 8);

    mylist.remove_if(single_digit); // mylist 자체를 수정
    mylist.remove_if(is_odd);

    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    return 0;
}