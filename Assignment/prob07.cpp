#include <iostream>

using namespace std;

int delmultiple(int *number, int arrayLength);

int main()
{
    int n;
    cin >> n;
    int number[n - 1] = {0};                         // 2부터 n까지의 정수를 담을 n-1 크기의 배열 정의, 배열 0으로 초기화
    int numArraySize = sizeof(number) / sizeof(int); // 배열의 사이즈 구하기

    for (int i = 0; i < n - 1; i++) // 2부터 n까지의 정수를 배열에 저장
        number[i] = i + 2;

    numArraySize = delmultiple(number, numArraySize);

    for (int i = 0; i < numArraySize; i++)
        cout << number[i] << endl;

    return 0;
}

/**
 * @brief 배열 내부에 소수만 남긴 후 남아있는 요소들의 크기를 반환하는 함수
 *
 * @param number 해당 배열의 주소
 * @param arrayLength 해당 배열의 길이
 * @return int 소수만 남아있는 연속된 요소들의 길이
 */
int delmultiple(int *number, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++) // 대상 정수
    {
        for (int j = i + 1; j < arrayLength; j++) // 대상 정수의 배수 찾기
        {
            if (number[j] % number[i] == 0)
            { // 배수라면

                for (int k = j; k < arrayLength; k++)
                    number[k] = number[k + 1]; // 한칸씩 앞으로 당기기

                arrayLength--; // 요소 하나가 없어졌으므로 arrayLength 1 감소
                j--;           // 전체적으로 한 칸 당겨졌으므로 j도 뒤로 한 칸 당겨주기
            }
        }
    }

    return arrayLength;
}
