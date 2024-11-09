#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
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

/**
 * @brief 컴포넌트의 크기를 구하는 함수
 * 
 * @param currPos 시작지점의 좌표
 * @return int 컴포넌트의 크기
 */
int findComponentSize(pair<int, int> currPos) {
    // 시작 지점 기억 위한 변수 정의
    pair<int, int> startPos = currPos;
    // 방문 표시
    image[startPos.first][startPos.second]++;
    // 컴포넌트 사이즈 정의
    int componentSize = 1;
    // 간 방향을 저장하는 stack 정의
    stack<int> dirStack;
    // dir을 반복문 내부에서 바꾸기 위해 반복문 바깥에서 정의
    int dir = 0;

    // while문의 끝을 정하기 위한 flag
    bool END = false;

    while(!END) {
        for (; dir < 8; dir++) {
            // 계산이 끝날 조건 확인
            if (currPos == startPos && image[currPos.first][currPos.second] > 1 
                    && dir == 7 && !moveable(currPos, dir)) {
                        END = true;
                        break;
            }

            // 1. dir 방향으로 움직일 수 있다면 방향을 스택에 넣은 후 움직이고 componentSize 1 추가
            if (moveable(currPos, dir)) {
                dirStack.push(dir);
                currPos = move_to(currPos, dir);

                image[currPos.first][currPos.second]++;
                componentSize++;
                dir = 0;        // dir 초기화
                break;
            }

            // 2. 모든 방향으로 움직일 수 없다면 스택의 top에 해당하는 방향의 반대방향으로 움직인 후 dir을 스택의 top에 해당하는 방향으로 조정
            else if (dir == 7 && !moveable(currPos, dir)) {
                int goBackDir = 7 - dirStack.top();
                dirStack.pop();
                currPos = move_to(currPos, goBackDir);
                dir = 7 - goBackDir;    // dir을 돌아온 방향에서 다시 시도
                break;
            }
        }
    }

    return componentSize;
}

/**
 * @brief 시작점을 정하고 findComponentSize을 실행시키는 함수
 */
void solveProblem() {
    bool isSolved = false;
    
    while (!isSolved) {
        pair<int, int> startPos;
        bool getStartPoint = false;
        // 1인 부분을 벡터 내에서 순차적으로 탐색하여 선택한다. (시작점 찾기)
        for (startPos.first = 0; startPos.first < imageSize; startPos.first++) {
            for (startPos.second = 0; startPos.second < imageSize; startPos.second++) {
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
            int componentSize = findComponentSize(startPos);
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
