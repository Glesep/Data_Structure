#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
bool moveable(pair<int, int> pos, int dir);
pair<int, int> move_to(pair<int, int> pos, int dir);
void findRoute();

int main()
{
    pullOneCase();
    findRoute();
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

bool moveable(pair<int, int> pos, int dir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];
    return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 0; // 0이 길 이라는 표시
}

pair<int, int> move_to(pair<int, int> pos, int dir)
{
    return pair<int, int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}

void findRoute()
{
    queue<pair<int, int>> que;
    pair<int, int> cur(0, 0);
    maze[cur.first][cur.second] = -1;
    que.push(cur);

    while (!que.empty())
    {
        cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            if (moveable(cur, dir))
            {
                pair<int, int> p = move_to(cur, dir);
                maze[p.first][p.second] = maze[cur.first][cur.second] - 1;
                if (p.first == mazeSize - 1 && p.second == mazeSize - 1)
                {
                    cout << "Found the path." << endl;
                    printmaze();
                    return;
                }
                que.push(p);
            }
        }
    }
    cout << "No path exists" << endl;
}

// 1 증가 -> 방향 저장 후 움직이기
// 다음 1증가 -> 전의 방향과 비교한 후 다르면 corner 인식
// 분기와 방향을 기억해? - 한 분기의 모든 경우의 수를 stack에 저장
// 한 경우의 수를 진행 시, stack top의 경우를 저장 후 stack pop
// 분기가 생겼다는 말은 코너의 경우가 무조건 생긴다는 것이다. - 분기로 돌아갈 때 corner--
// 한 분기의 모든 경우를 다 시도했을 경우 이전 분기로 넘어가기 - 이전 분기에서 갔던 방향 다음 방향부터 탐색

int countMinCorner() {
    int minCorner;
    pair<int, int> startPos (mazeSize-1, mazeSize-1);   // 출구에서부터 세기

    




    return minCorner;
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
