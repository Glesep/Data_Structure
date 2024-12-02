/*
인접하다는 의미만 생각을 바꿔보기
내가 한번에 갈 수 있는(일자로 갈 수 있는) 모든 길이 인접하다고 생각해보자
movaable을 recursion으로
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int mazeSize = 0;
vector<vector<int>> maze;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},  // 북
                    {0, 1},   // 동
                    {1, 0},   // 남
                    {0, -1}}; // 서

void pullOneCase();
void printmaze(); // debug
bool moveable(pair<int, int> pos, int dir);  
pair<int, int> move_to(pair<int, int> pos, int dir);
void checkCorner(pair<int, int> currPos, int lastDir = -1, int visitedWithCntCorner = -1); // default param은 한 곳에만 정의

int main()
{   
    pullOneCase();

    // 시작 위치 정의
    pair<int, int> currPos = pair<int, int>(0,0);

    checkCorner(currPos);
    
    cout << maze[mazeSize-1][mazeSize-1] + 1 << endl;

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

/**
 * @brief 갈 수 있음: 방문하지 않은 곳이거나(0) 현재 위치에서 다음 위치로 갈 때 기록할 코너의 수보다 갈 위치에서 현재 기록된 코너의 수가 더 많음
 * 
 * @param pos 
 * @param dir 
 * @param lastDir 
 * @return true 
 * @return false 
 */
bool moveable(pair<int, int> pos, int dir, int lastDir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];

    // 코너가 아닐 경우
    if (dir == lastDir)
        return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && (maze[x][y] == 0 || maze[x][y] <= maze[pos.first][pos.second]);
    // 코너일 경우
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

중요! - 현재 노드의 정보(매개변수에서 받아온 정보)를 완전 바꿔버리면 다시 돌아올 때 의도치 않은 행동을 할 수 있음
*/

/**
 * @brief 코너의 수를 체크하면서 전체 경로를 순회하는 함수
 * 
 * @param currPos 현재 위치 (초기값: 시작 위치)
 * @param lastDir 최근 움직인 방향 (초기값: -1)
 * @param visitedWithCntCorner 방문했음(-1), 방문했음+코너개수(-2 ~)
 */
void checkCorner(pair<int, int> currPos, int lastDir, int visitedWithCntCorner) {
    // 현재 값 초기화
    maze[currPos.first][currPos.second] = visitedWithCntCorner;

    for (int dir = 0; dir < 4; dir++) {
        if (!moveable(currPos, dir, lastDir)) {  // 현재 방향으로 못 간다면 다음 방향 확인
            continue;
        }
        // 현재 방향으로 진행할 수 있을 때
        
        // 코너인 경우(이전 방향과 반대방향인 경우 && 처음 시작하는 게 아닌경우)
        if (lastDir != dir && lastDir != -1)
            checkCorner(move_to(currPos, dir), dir, visitedWithCntCorner-1);
        
        // 코너가 아닌 경우
        else
            checkCorner(move_to(currPos, dir), dir, visitedWithCntCorner);
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
