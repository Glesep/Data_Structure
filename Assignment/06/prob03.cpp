#include <iostream>

#define MAX 1000
using namespace std;

int data[MAX];
int N, K;
void two_sum(int start, int end, int count);
/*
오름차순으로 정렬된 N<=1000개의 서로 다른 정수와 또 다른 하나의 정수 K가 입력으로 주어짐
N개의 정수들 중에서 합이 K가 되는 정수 쌍의 개수 카운트
*/
int main()
{
    // 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    cin >> K;

    two_sum(0, N-1, 0);

    return 0;
}

/**
 * @brief 2-SUM 문제 알고리즘을 재귀함수로 표현
 * 
 * @param start 0
 * @param end N-1
 * @param count 합이 K가 되는 정수 쌍의 개수
 */
void two_sum(int start, int end, int count) {

    int sum = data[start] + data[end];

    if (start >= end) {
        cout << count << endl;
        return;
    }

    else if (sum > K) {
        two_sum(start, end-1, count);
    }

    else if (sum < K) {
        two_sum(start+1, end, count);
    }

    else {
        two_sum(start+1, end-1, count+1);
    }
}