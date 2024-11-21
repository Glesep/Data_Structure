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
bool moveable(pair<int, int> pos, int dir, bool retraverse=false);  // default param은 한 곳에만 정의
pair<int, int> move_to(pair<int, int> pos, int dir);
void findRoute();
void findMinCorner(pair<int,int> currPos, int countCorner, int &minCorner, int lastDir = -1);

int main()
{   
    pullOneCase();
    findRoute();
    // printmaze();

    int minCorner = -1;
    findMinCorner(pair<int, int> (mazeSize-1, mazeSize-1), 0, minCorner);

    cout << minCorner << endl;
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

bool moveable(pair<int, int> pos, int dir, bool retraverse)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];

    if (retraverse)
        return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == maze[pos.first][pos.second]+1;

    return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 0; // 0이 길 이라는 표시
}


pair<int, int> move_to(pair<int, int> pos, int dir)
{
    return pair<int, int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}

// 가면서 체크하기도 고려한다.
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
                    // cout << "Found the path." << endl;
                    // printmaze();
                    // return;
                }
                que.push(p);
            }
        }
    }
    cout << "END" << endl;
    printmaze();
}

/*
도착지에서 시작
최대한 직선으로 가도록 유도
출발지에 도달하면 min 변수와 비교
가장 작은 수 출력
*/
// void findMinCorner(pair<int,int> currPos, int lastDir = -1) {
//     int countCorner = 0;
//     for (int dir = 0; dir < 4; dir++) {
//         // 움직일 수 있을 때
//         if (moveable(currPos, dir, true)) {
//             // 처음 움직이는 것이면
//             if (lastDir < 0) {
//                 findMinCorner(move_to(currPos, dir), dir);
//             }

//             else if (dir != lastDir)
//                 countCorner++;
                
//             }
//         }

        

//     }
// }

void findMinCorner(pair<int,int> currPos, int countCorner, int &minCorner, int lastDir) {
    bool isCorner = false;

    for (int dir = 0; dir < 4; dir++) {
        // 이전이 코너로 인식되었다면
        if (isCorner) {
            countCorner--;
            isCorner = false;
        }

        // 움직일 수 있으면
        if (moveable(currPos, dir, true)) {
            if (dir != lastDir && lastDir >= 0) {
                if (countCorner+1 >= minCorner && minCorner != -1)
                    continue;
                
                countCorner++;
                isCorner = true;
            }

            findMinCorner(move_to(currPos, dir), countCorner, minCorner, dir);
        }
    }
    // 출발지에 도착했을 때, 최소랑 비교
    if (currPos.first == 0 && currPos.second == 0) {
        cout << "Change to " << countCorner << endl;
        minCorner = countCorner;
    }

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
