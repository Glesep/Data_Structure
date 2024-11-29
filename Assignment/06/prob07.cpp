#include <iostream>
#include <fstream>
using namespace std;

void isLuckyNum(int n, ifstream &infile);

int main()
{
    ifstream infile("lucky_numbers.txt");
    
    isLuckyNum(138553, infile);

    infile.close();
    
    return 0;
}

void isLuckyNum(int n, ifstream &infile) {
    int compareNum;
    // 값을 읽어왔을 때
    if (infile >> compareNum) {
        if (n == compareNum) {
            cout << "yes" << endl;
            return;
        }

        // 전부 다 비교하는 것은 비효율적이라 생각, n보다 compareNum이 더 클 때는 무조건 없는 것이므로 바로 no 출력
        else if (n < compareNum) {
            cout << "no" << endl;
            return;
        }

        else
            isLuckyNum(n, infile);
    }

    // 값을 읽지 못했을 때
    else 
        cout << "no" << endl;
}