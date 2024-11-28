#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool IsOnlyOne(string num);
string numToString(int num);
string makeOpposite(string num);
void findTarget(string num, string oppositeNum, string result, int K);

vector<string> setOfResult;

int main()
{
    string binarySeq;
    int K;
    cin >> binarySeq;
    cin >> K;

    cout << "h" << endl;
    findTarget(binarySeq, makeOpposite(binarySeq), "", K);
    

    
    
    return 0;
}

/* 16
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/
/*
해야 하는 것 
binarySeq의 길이 N을 찾기 - 벡터로 쪼개기
*/

/**
 * @brief 전체가 1인가 확인
 * 
 * @param num string 타입의 이진수
 * @return true 1밖에 없음
 * @return false 0이 존재함
 */
bool IsOnlyOne(string num) {
    return num.find_first_not_of("1") == string::npos;
}

string makeOpposite(string num) {
    string result = "";
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '0')
            result += "1";
        else
            result += "0";
    }

    return result;
}

/*
num과 같은 요소가 없는 변수를 만들기
K만큼 고르기
    인덱스를 하나 고르고 다음 인덱스 고르기
*/
// 000 11000
void findTarget(string num, string oppositeNum, string result, int K) {
    // Base Case
    if (K == 0) {
        // K만큼 바꿨는데 전체를 탐색하지 않았다면
        if (result.length() != num.length()) {
            // 부족한 부분은 num의 일부로 채우기
            result + num.substr(result.length());
        }
        cout << result << endl;
        return;
    }
    // General Case
    else {
        for (int i = 0; i < num.length(); i++) {
            findTarget(num.remove(i,1), oppositeNum.erase(i,1),
                            result+oppositeNum[i], K-1);
        }
    }
}