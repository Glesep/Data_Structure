#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<int>> image; // image가 담길 2차원 벡터
int imageSize;  // image의 크기


// /**
//  * @brief 이미지 프린트 (debug용)
//  */
// void printImage() {
//     for (int i = 0; i < imageSize; i++) {
//         for (int j = 0; j < imageSize; j++) {
//             cout << image[i][j] << " ";
//         }
//         cout << '\n';
//     }
// }

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 * 
 * @param infile ifstream
 */
void pullOneCase(ifstream &infile) {
    infile >> imageSize;

    for (int i = 0; i < imageSize; i++) {
        vector<int> vec;
        for (int j = 0; j < imageSize; j++) {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        image.push_back(vec);
    }
}

// x, y좌표 변화량 정의
// 반대 방향끼리의 합이 7이 되도록 구성
int offset[8][2] {
    {-1, 0},        // 북 0
    {-1, 1},        // 북동 1
    {0, 1},         // 동 2
    {1, 1},         // 남동 3
    {-1, -1},       // 북서 4
    {0, -1},        // 서 5    
    {1, -1},        // 남서 6
    {1, 0}          // 남 7
};

/**
 * @brief currPos(현재 위치)에서 dir 방향으로 움직일 수 있는지 판단하는 함수
 * 
 * @param currPos 현재 위치
 * @param dir 가고 싶은 방향
 * @return true 
 * @return false 
 */
bool moveable(pair<int, int> currPos, int dir) {
    int x = currPos.first + offset[dir][0];
    int y = currPos.second + offset[dir][1];

    return x >= 0 && x < imageSize &&
            y >= 0 && y < imageSize &&
            image[x][y] == 1;
}

/**
 * @brief currPos(현재 위치)에서 dir 방향으로 움직이는 함수
 * 
 * @param currPos 현재 위치
 * @param dir 방향
 * @return pair<int, int> 움직인 다음 위치
 */
pair<int, int> move_to(pair<int, int> currPos, int dir)
{
    pair <int, int> nextPos (currPos.first + offset[dir][0],
                            currPos.second + offset[dir][1]);

    return nextPos;
}



// 아이디어 : 컴포넌트 하나의 크기를 다 구했으면 무조건 startPoint로 온다.

/*
currPos에 참조 사용한 이유 : 재귀함수는 함수 종료 후 되돌아갈 때 이전에 저장되었던 변수를 들고오기 때문에 
                         3번째 경우 currPos를 바꿔도 적용이 되지 않음
*/

/**
 * @brief component 위를 움직이면서 componentSize를 계산하는 함수
 * 
 * @param currPos 현재 위치
 * @param componentSize 
 * @param oppositeDirStack 움직인 방향의 반대 방향을 담는 스택
 */
void culculateSize(pair<int, int> &currPos, int &componentSize, stack<int> &oppositeDirStack) {
    
    for (int dir = 0; dir < 8; dir++) {

        if (moveable(currPos, dir)) {
            oppositeDirStack.push(7-dir); // 움직일 방향의 반대 방향을 stack에 저장한다.
            currPos = move_to(currPos, dir);
            image[currPos.first][currPos.second]++; // 도착 위치에 1을 더해 방문했음을 알림
            componentSize++;    // componentSize 체크

            culculateSize(currPos, componentSize, oppositeDirStack);    // 재귀함수
        }

        // dir == 7일 때 위의 if문이 실행되었다면 else if로 구성시 다 무시되는 현상 발생 - if로 조정
        // startPos에서 갈 곳이 없을 경우 끝내기
        if (dir == 7 && oppositeDirStack.empty()) {
            break;
        }

        // 더 이상 갈 곳이 없을 때, 이전 위치로 돌아가기
        if(dir == 7 && !moveable(currPos, dir)) {
            // 직전에 있던 위치로 돌아가기
            /*
            아래 라인을 실행 후 재귀함수 종료 시 currPos가 값에 의한 호출이었다면 그 상황의 값으로 변환됨.
            따라서 매개변수 currPos를 참조에 의한 호출로 받아 값을 내가 컨트롤할 수 있도록 설계
             */
            currPos = move_to(currPos, oppositeDirStack.top());     
            oppositeDirStack.pop();
        }

        
    }
}


int findComponentSize(pair<int, int> currPos, stack<int> &oppositeDirStack) {
    // startPoint 정의
    pair<int, int> startPos = currPos;
    // 방문하였으면 1 증가 (startPoint)
    image[currPos.first][currPos.second]++;
    int componentSize = 1;


    // ============== 아래부터 재귀함수 ============== 
    culculateSize(currPos, componentSize, oppositeDirStack);

    return componentSize;
}

// 1. 1인 부분을 랜덤으로 선택한다. (시작점 찾기)
// 2. 인접한 곳을 다 찾는다.
// 3. 1인 부분을 다시 찾는다.
void solveProblem() {
    bool isSolved = false;
    stack<int> oppositeDirStack;
    while (!isSolved) {
        pair<int, int> startPos;
        bool getStartPoint = false;
        // 1인 곳에 시작 지점을 정한다.
        for (startPos.first = 0; startPos.first < imageSize; startPos.first++) {
            for (startPos.second = 0; startPos.second< imageSize; startPos.second++) {
                if (image[startPos.first][startPos.second] == 1) {
                    getStartPoint = true;
                    break;
                }
            }

            if (getStartPoint)
                break;
        }
        
        // 더 이상 시작 지점을 구할 수 없다면 (문제가 풀렸다면)
        if (!getStartPoint) {
            cout << '\n';
            isSolved = true;
        }

        else {
            // 문제풀이 시작
            int componentSize = findComponentSize(startPos, oppositeDirStack);
            cout << componentSize << " ";
        }
    }
}




int main()
{
    ifstream infile("input.txt");
    int CASE;
    infile >> CASE;

    // 테스트 케이스 3개 수행
    for (int i = 0; i < CASE; i++) {
        pullOneCase(infile);
        solveProblem();
        image.clear();
    }

    infile.close();
    
    return 0;
}
