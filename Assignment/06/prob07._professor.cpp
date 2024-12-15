#include <iostream>

using namespace std;

/*

1 2 3 4 5 6 7   : 실제 수
1 2 1 2 1 2 1   : counter == 2로 시작

지워지는 것의 개수는 n/counter 개

1 3 5 7
1 2 3 1

1 3 7
1 2 3 4 -> 현재 남은 수보다 counter가 더 큼 - 행운수 탐색 종료
*/


bool isLuckyRecursive(int n, int counter) {
    if (counter > n)
        return true;
    if (n % counter == 0)   // n번째 수가 counter 번째 수로 나눠지는가?
        return false;
    
    int next_pos = n - n/counter;
    return isLuckyRecursive(next_pos, counter + 1);
}

bool isLucky(int n) {
    if (n <= 0)
        return false;
    return isLuckyRecursive(n, 2);  // n이 행운수인가? -> 1~n까지 있는 집합에서 확인한다고 생각하자
}

int main()
{
    int n;
    cin >> n;

    if (isLucky(n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
