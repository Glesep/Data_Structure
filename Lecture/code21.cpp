#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> sentence{"how", "fun", "is", "programming"};

    // "fun"을 삭제해보자.
    sentence[1] = sentence[2];
    sentence[2] = sentence[3];
    sentence.pop_back();
    
    for (auto s : sentence)
        cout << s << endl;
    return 0;
}