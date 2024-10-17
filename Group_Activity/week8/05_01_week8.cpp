#include <iostream>
#include <list>  
using namespace std;

int main()
{

    // 
    list<int> mylist(2, 100);
    mylist.push_front(200);
    mylist.push_front(300);

    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';
    
    return 0;
}
