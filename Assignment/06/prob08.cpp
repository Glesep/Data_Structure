#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void pullOneCase(ifstream &infile);
void printGround();
pair<int, int> pullPos(ifstream &infile);
bool moveable(pair<int,int> currPos, pair<int, int> destPos, int dir);
void canCannonMove(pair<int, int> startPos, pair<int, int> currPos, pair<int, int> targetPos, bool &isFound);
bool inGround(pair<int, int> pos);


int groundSize = 0;
vector<vector<int>> ground;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},  // 북
                    {0, 1},   // 동
                    {1, 0},   // 남
                    {0, -1}}; // 서

int main()
{
    ifstream infile("input8.txt");

    pullOneCase(infile);

    pair<int, int> startPos = pullPos(infile);
    pair<int, int> targetPos = pullPos(infile);

    infile.close();

    bool isFound = false;
    canCannonMove(startPos, startPos, targetPos, isFound);  
    

    return 0;
}


/**
 * @brief 포가 일직선상에서 destPos 까지 움직일 수 있는가를 판단하는 함수
 * 
 * @param currPos 현재 위치
 * @param destPos 목적지
 * @param dir 방향 (이 방향으로만 간다)
 * @return true
 * @return false 
 */
bool moveable(pair<int,int> currPos, pair<int, int> destPos, int dir) {
    pair<int, int> tmpPos = currPos;
    // 경로 상의 이미 다른 말이 놓인 칸의 횟수
    int object = 0;

    // 가고 싶은 지점에 말이 놓여져 있을 경우(1) && 갔던 곳인 경우(-1)
    if (ground[destPos.first][destPos.second] != 0)
        return false;

    // tmpPos가 ground 내에 있으면 destPos까지 순차적으로 경로 탐색
    while(inGround(tmpPos) && tmpPos != destPos) {
        // 이미 말이 놓여져 있으면
        if (ground[tmpPos.first][tmpPos.second] == 1) {
            object++;
        }
        // 한 칸 이동
        tmpPos = pair<int,int> (tmpPos.first + offset[dir][0], tmpPos.second + offset[dir][1]);
    }

    // destPos에 도착할 때까지 말이 있었던 횟수가 1개라면 갈 수 있는 곳
    if (object == 1)
        return true;

    else
        return false;
}

/*
base case:
1. 찾았을 때
2. 못 찾았을 때

general case:
1. 4방향 검사
    검사 중 갈 수 있는 길이면 그 곳으로 이동 후 다시 4방향 검사
    방향에 놓여있는 모든 길 검사

*/

/**
 * @brief 포가 움직일 수 있는 경로가 존재하는지 파악하는 함수 - 존재시 Yes, 존재하지 않을 시 No
 * 
 * @param startPos 시작 지점
 * @param currPos 현재 지점 (default = startPos)
 * @param targetPos 목표 지점
 * @param isFound 경로가 있는지 확인하는 flag (defalut = false)
 */
void canCannonMove(pair<int, int> startPos, pair<int, int> currPos, pair<int, int> targetPos, bool &isFound) {
    ground[currPos.first][currPos.second] = -1; // 방문 표시 해야 다음에 여기는 안옴 - 경우의 수 줄이기

    // 경로를 찾았을 때
    if (currPos == targetPos) {
        isFound = true;
        return;
    }

    // 4 방향을 검사
    for (int dir = 0; dir < 4; dir++) {
        pair<int, int> tmpPos (currPos.first + offset[dir][0], currPos.second + offset[dir][1]);

        // 한 방향에 위치한 모든 길을 검사
        while(inGround(tmpPos)) {
            // 갈 수 있다면 진행
            if (moveable(currPos, tmpPos, dir)) {
                canCannonMove(startPos, tmpPos, targetPos, isFound);
            }
            // 못 간다면 같은 방향의 다음 경로 확인
            else {
                tmpPos = pair<int, int> (tmpPos.first + offset[dir][0], tmpPos.second + offset[dir][1]);
            }
        }
    }

    // 모든 경우를 보고 다시 출발지로 되돌아왔을 때
    if (currPos == startPos) {
        if (isFound)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
}

// pos가 ground 위에 있는가 확인하는 함수
bool inGround(pair<int, int> pos) {
    return pos.first >= 0 && pos.first < groundSize && pos.second >=0 && pos.second < groundSize;
}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 *
 * @param infile ifstream
 */
void pullOneCase(ifstream &infile)
{
    infile >> groundSize;
    // 처음 불러올 때
    for (int i = 0; i < groundSize; i++)
    {
        vector<int> vec;
        for (int j = 0; j < groundSize; j++)
        {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        ground.push_back(vec);
    }
}

/**
 * @brief 파일에서 위치 정보 추출하는 함수
 *
 * @param infile ifstream
 * @return pair<int, int> 위치 정보
 */
pair<int, int> pullPos(ifstream &infile)
{
    int x, y;
    infile >> x >> y;

    return pair<int, int>(x, y);
}

/**
 * @brief ground 프린트 (debug용)
 */
void printGround()
{
    cout << groundSize << endl;

    for (int i = 0; i < groundSize; i++)
    {
        for (int j = 0; j < groundSize; j++)
        {
            cout << ground[i][j] << " ";
        }
        cout << '\n';
    }
}