#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int *count = new int;           // 몇 개의 정수를 입력받을지에 대한 변수 정의
    double *sum = new double;       // 합계 변수 정의
    int *min = new int;             // 최솟값 변수 정의
    int *max = new int;             // 최댓값 변수 정의

    cin >> *count;                  

    int *nums = new int[*count];

    cin >> *(nums+(*count-1));         // 처음 값을 먼저 받음

    *min = *(nums+(*count-1));        // 초기 변수 값 설정
    *max = *(nums+(*count-1));
    *sum = *(nums+(*count-1));

    int *i = new int ((*count)-2);
    

    // *연산자보다 --연산자가 더 높은 우선순위
    for (; *i >= 0 ; (*i)--){
        cin >> *(nums+((*i)));                                      // index 3부터 입력받음
        *sum += *(nums+((*i)));       

        if (*min > *(nums+(*i)))                                    // 최솟값 조정
            *min = *(nums+(*i));

        if (*max < *(nums+(*i)))                                    // 최댓값 조정
            *max = *(nums+(*i));



    }
    if (*i == 0)                                                    // garbage 삭제
        delete i;


    cout << *min << " " << *max << " ";                             // 최소 최대 출력
    double *average = new double(*sum/(*count));                    // 평균 변수 정의
    cout << *average << " ";                                        // 평균 출력



    double *deviationSquareSum = new double(0);                     // 편차의 제곱의 합 변수 정의

    for (int *i = new int(*count-1); *i >= 0; (*i)--) {
        *deviationSquareSum += pow(*(nums+(*i))-(*average), 2);     // 편차제곱의 합
        // cout << *deviationSquareSum << endl;
    }
    if (*i == 0)                                                    // garbage 삭제
        delete i;               

    double *std = new double(sqrt(*deviationSquareSum/(*count)));   // 표준편차 정의

    cout << *std << endl;
    

    // ===================================================================
    delete count;                   // garbage 삭제
    delete [] nums;
    delete sum;
    delete min;
    delete max;
    delete average;
    delete deviationSquareSum;
    delete std;
    return 0;
}
