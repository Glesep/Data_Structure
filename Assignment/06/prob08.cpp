#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void pullOneCase(ifstream &infile);
void printGround();
pair<int, int> pullPos(ifstream &infile);

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
    
    
    return 0;
}

/*
한놈 넘긴 표시를 해야됨
*/

bool moveable(pair<int, int> currPos, pair<int, int> targetPos, int dir, bool isOnlyOneObject) {
    // isOnlyOneObject: 경로에 하나의 장애물만 있는지 판단하는 flag

    // 목적지 자체가 장애물이라면
    if (ground[targetPos.first][targetPos.second] == 1)
        return false;

    // 현재 위치가 목적지라면 flag 출력
    if (currPos == targetPos) {
        return isOnlyOneObject;
    }
    else {
        // 현재 위치에 장애물이 존재한다면
        if (ground[currPos.first][currPos.second] == 1) {
            isOnlyOneObject = !isOnlyOneObject;
        }

        return moveable(pair<int, int> (currPos.first+offset[dir][0],
                                        currPos.first+offset[dir][1]),
                        targetPos, dir, isOnlyOneObject);
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

pair<int, int> pullPos(ifstream &infile) {
    int x, y;
    infile >> x >> y;

    return pair<int,int> (x, y);
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