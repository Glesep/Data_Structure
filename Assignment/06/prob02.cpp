#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 경로가 꺾인 최소 횟수 -> 최단 경로 중 하나

/*
1. 최단 경로 구하기
2. 최단 경로를 역으로 타고 가면서 꺾인 부분 세기
*/

int mazeSize = 0;
vector<vector<int>> maze;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},  // 북
                    {0, 1},   // 동
                    {1, 0},   // 남
                    {0, -1}}; // 서

void pullOneCase();
void printmaze(); // debug
bool moveable(pair<int, int> pos, int dir);  // default param은 한 곳에만 정의
pair<int, int> move_to(pair<int, int> pos, int dir);
void checkCorner(pair<int, int> currPos, int lastDir = -1, int visitedWithCntCorner = -1); 

int main()
{   
    pullOneCase();

    pair<int, int> currPos = pair<int, int>(0,0);
    maze[currPos.first][currPos.second] = -1;

    checkCorner(currPos);
    printmaze();

    return 0;
}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 *
 * @param infile ifstream
 */
void pullOneCase()
{
    ifstream infile("input2.txt");
    infile >> mazeSize;
    // 처음 불러올 때
    for (int i = 0; i < mazeSize; i++)
    {
        vector<int> vec;
        for (int j = 0; j < mazeSize; j++)
        {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        maze.push_back(vec);
    }

    infile.close();
}

bool moveable(pair<int, int> pos, int dir, int lastDir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];

    if (dir == lastDir)
        return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && (maze[x][y] == 0 || maze[x][y] <= maze[pos.first][pos.second]);
    else
        return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && (maze[x][y] == 0 || maze[x][y] < maze[pos.first][pos.second]);

}


pair<int, int> move_to(pair<int, int> pos, int dir)
{
    return pair<int, int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}

/*
방문했음 : -1
꺾였음 : 현재 위치의 수에 -1 빼주기

방문할 수 있는 조건 : 방문할 위치가 아예 방문하지 않은 곳(0)이거나 현재 위치의 수보다 작을 때
*/
void checkCorner(pair<int, int> currPos, int lastDir, int visitedWithCntCorner) {
    // 처음 값 초기화
    if (currPos.first == 0 && currPos.second == 0) {
        maze[currPos.first][currPos.second] = -1;
    }

    for (int dir = 0; dir < 4; dir++) {
        if (!moveable(currPos, dir, lastDir)) {  // 현재 방향으로 못 간다면 다음 방향 확인
            continue;
        }
        // 현재 방향으로 진행할 수 있을 때
        
        // 이전 방향과 반대방향인 경우 && 처음 시작하는 게 아닌경우
        if (lastDir != dir && lastDir != -1) {
            visitedWithCntCorner--;
        }
        currPos = move_to(currPos, dir);
        maze[currPos.first][currPos.second] = visitedWithCntCorner;
        checkCorner(currPos, dir, visitedWithCntCorner);
    }

    // 다 못갈 때 함수 그냥 종료



}


/**
 * @brief maze 프린트 (debug용)
 */
void printmaze()
{
    cout << mazeSize << endl;

    for (int i = 0; i < mazeSize; i++)
    {
        for (int j = 0; j < mazeSize; j++)
        {
            cout << maze[i][j] << "\t";
        }
        cout << '\n' << '\n';
    }
}
