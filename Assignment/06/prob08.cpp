#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void pullOneCase(ifstream &infile);
void printGround();
pair<int, int> pullPos(ifstream &infile);
bool moveable(pair<int, int> currPos, pair<int, int> targetPos, int dir, int cntObject=0);

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
    pair<int, int> currPos = pullPos(infile);
    pair<int, int> targetPos = pullPos(infile);

    infile.close();
    if (moveable(pair<int, int>(1, 0), pair<int, int>(1, 7), 1, 0))
    {
        cout << "yes" << endl;
    }
    else
        cout << "no" << endl;

    return 0;
}

/*
한놈 넘긴 표시를 해야됨
*/

/**
 * @brief currPos에서 targetPos까지 갈 수 있는지 확인(일직선상에서만 가능)
 *
 * @param currPos 시작 위치
 * @param targetPos 도착 위치
 * @param dir 방향(이 방향으로만 감)
 * @param cntObject 경로에 하나의 장애물만 있는지 판단을 위한 정수형 변수, 초깃값 0
 * @return true
 * @return false
 */
bool moveable(pair<int, int> currPos, pair<int, int> targetPos, int dir, int cntObject)
{
    // cntObject: 경로에 하나의 장애물만 있는지 판단을 위한 정수형 변수

    // 목적지 자체가 갈 수 없는 곳이라면
    if (ground[targetPos.first][targetPos.second] != 0)
        return false;

    // 현재 위치가 목적지라면
    if (currPos == targetPos)
    {
        // 장애물을 한번 넘었을 때
        if (cntObject == 1)
        {
            return true;
        }
        else
            return false;
    }
    // 갈 수 있는 곳에 접근했을 때
    else if (currPos.first >= 0 &&
             currPos.first < groundSize &&
             currPos.second >= 0 &&
             currPos.second < groundSize)
    {
        // 현재 위치에 장애물이 존재한다면
        if (ground[currPos.first][currPos.second] == 1)
        {
            return moveable(pair<int, int>(currPos.first + offset[dir][0],
                                           currPos.second + offset[dir][1]),
                            targetPos, dir, cntObject + 1);
        }
        else
            return moveable(pair<int, int>(currPos.first + offset[dir][0],
                                           currPos.second + offset[dir][1]),
                            targetPos, dir, cntObject);
    }

    // 그 이외에는 못 감
    return false;
}

// 갈 수 있으면 움직이고, 못가면 다음 칸 보기
void canCannonGo(pair<int, int> currPos, pair<int, int> targetPos, bool &isFound)
{
    // 길을 못찾았을 때만 수행
    if (!isFound)
    {
        if (currPos == targetPos)
        {
            isFound = true;
            cout << "yes" << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> tmpPos(currPos.first + offset[dir][0],
                                                currPos.second + offset[dir][1]);

            if (moveable(currPos, tmpPos, dir)) {
                ground[currPos.first][currPos.second] = -1;
                canCannonGo(tmpPos, targetPos, isFound);
            }
            
        }
        ground[currPos.first][currPos.second] = 0;

    }
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