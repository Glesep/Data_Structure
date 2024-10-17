#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> mylist;
    mylist.push_back(100);
    mylist.push_back(200);
    mylist.push_back(300);

    while(!mylist.empty()) {
        cout << ' ' << mylist.front();
        mylist.pop_front();
    }
    
    return 0;
}
