#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data {1, 2, 3, 4};

    for (int &t : data) {
        t += 1;
    }
    for (int t : data) {
        cout << t << " ";  
    }
    cout << '\n';
    
    return 0;
}
