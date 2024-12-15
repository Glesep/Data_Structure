#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string makeOpposite(string num);
void findTarget(int currPos, string result, int K);

// 이진수를 저장하는 전역변수
string binarySeq, oppositeBinarySeq;

int main()
{
    int K;
    cin >> binarySeq;
    cin >> K;

    oppositeBinarySeq = makeOpposite(binarySeq);
    findTarget(0, "", K);
    
    
    return 0;
}

/**
 * @brief bitwise not 수행 함수
 * 
 * @param num 바꾸고 싶은 수
 * @return string 바꿔진 수
 */
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

/**
 * @brief K개의 비트를 반전시키는 모든 경우를 출력해주는 함수
 * 
 * @param startPos 현재 가리키고 있는 인덱스
 * @param result 결과 값 저장 변수
 * @param K 남은 비트 반전 횟수
 */
void findTarget(int startPos, string result, int K) {
    // K가 0일 때 - 비트 반전을 다 수행했을 때
    if (K == 0) {
        // 뒤에 남은 수가 있을 수 있음
        result += binarySeq.substr(result.length());
        cout << result << endl;
        return;
    }
    
    else if (startPos < binarySeq.length()){
        // 국소적으로 한 부분만 봤을 때 어떤 케이스가 있는지를 생각 후 전체적으로 넓게 보기

        // 자기 위치에서 바꾸거나
        findTarget(startPos+1, result+oppositeBinarySeq[startPos], K-1);
        // 자기 위치에서는 안바꾸거나 (마지막 비트에서 접근하면 startPos가 oppositeBinarySeq의 인덱스를 넘어가면서 오류)
        findTarget(startPos+1, result+binarySeq[startPos], K);
    }
    // 가지치기 - 절대 안되는 경우는 고려하지 않는다.
    
}
