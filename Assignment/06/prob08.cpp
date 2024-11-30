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
/*
포는 무조건 장애물을 하나만 넘어야 이동 가능
 */

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

/*
한놈 넘긴 표시를 해야됨
*/

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

    // 가고 싶은 지점에 말이 놓여져 있을 경우 && 갔던 곳인 경우
    if (ground[destPos.first][destPos.second] != 0)
        return false;

    while(tmpPos.first >= 0 && tmpPos.first < groundSize && tmpPos.second >= 0 && tmpPos.first < groundSize && tmpPos != destPos) {
        if (ground[tmpPos.first][tmpPos.second] == 1) {
            object++;
        }

        tmpPos = pair<int,int> (tmpPos.first + offset[dir][0], tmpPos.second + offset[dir][1]);
    }

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
void canCannonMove(pair<int, int> startPos, pair<int, int> currPos, pair<int, int> targetPos, bool &isFound) {
    if (currPos == targetPos) {
        isFound = true;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        pair<int, int> tmpPos (currPos.first + offset[dir][0], currPos.second + offset[dir][1]);

        while(inGround(tmpPos)) {
            if (moveable(currPos, tmpPos, dir)) {
                ground[currPos.first][currPos.second] = -1; // 방문 표시 해야 다음에 여기는 안옴 - 경우의 수 줄이기
                canCannonMove(startPos, tmpPos, targetPos, isFound);
            }
            else {
                tmpPos = pair<int, int> (tmpPos.first + offset[dir][0], tmpPos.second + offset[dir][1]);
            }
        }
    }

    if (currPos == startPos) {
        if (isFound)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    
}

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