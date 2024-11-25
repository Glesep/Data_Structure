#include <iostream>
    
using namespace std;
#define MAX 1000

int data[MAX];
int N, K;
void floor(int start, int end);
void ceiling(int start, int end);

int main()
{
     // 입력
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }
    cin >> K;

    floor(0, N-1);
    ceiling(0, N-1);
    return 0;
}
/**
 * @brief floor 연산자 구현
 * 
 * @param start 0
 * @param end N-1
 */
void floor(int start, int end) {
    int mid = (start + end) / 2;

    // not found
    if (start > end) {
        cout << -1 << endl;
        return;
    }

    // case 1
    else if (data[mid] == K) {
        cout << data[mid] << endl;
        return;
    }

    else if (data[mid] > K) {
        floor(start, mid-1);
    }

    else if (data[mid] < K) {
        // case 2
        if (start == end-1) {
            if (data[end] < K)
                cout << data[end] << endl;
            else
                cout << data[mid] << endl;
            return;
        }
        // case 3
        else if (start == end) {
            cout << data[mid] << endl;
            return;
        }
        // mid+1을 해주면 정답 후보가 제외될 수 있다
        floor(mid, end);
    }
}

void ceiling(int start, int end) {
    int mid = (start + end) / 2;

    // not found
    if (start > end) {
        cout << -1 << endl;
        return;
    }

    // case 1
    else if (data[mid] == K) {
        cout << data[mid] << endl;
        return;
    }

    else if (data[mid] > K) {
        // case 2
        if (start == end-1) {
            cout << data[mid] << endl;
            return;
        }
        // case 3
        else if (start == end) {
            cout << data[mid] << endl;
            return;
        }
        // mid+1을 해주면 정답 후보가 제외될 수 있다
        ceiling(start, mid);
    }

    else if (data[mid] < K) {
        
        ceiling(mid+1, end);
    }
}
