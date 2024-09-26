#include <iostream>
#include <string>
using namespace std;

const int MAXWORDS = 100;

int main() {
    string words[MAXWORDS];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        cout << words[i] << endl;
    }
    
    return 0;
}
