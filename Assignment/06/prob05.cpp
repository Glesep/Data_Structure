#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int mazeSize = 0;
vector<vector<int>> maze;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},  // 북
                    {0, 1},   // 동
                    {1, 0},   // 남
                    {0, -1}}; // 서

int cntRoute = 0;

void printmaze();
void pullOneCase();
bool moveable(pair<int, int> pos, int dir);
pair<int, int> move_to(pair<int, int> pos, int dir);
void findAllRoute(pair<int, int> currPos);

int main()
{
    pullOneCase();
    // printmaze();
    findAllRoute(pair<int, int> (0,0));
    cout << cntRoute << endl;
    
    
    return 0;
}


/*
꽝
마무리 성공
General
*/
/**
 * @brief 모든 경로를 찾는 함수, 돌아갈 때 자신의 흔적을 지우면서 가기
 * 
 * @param currPos (0,0)
 */
void findAllRoute(pair<int, int> currPos) {
    maze[currPos.first][currPos.second] = -1;
    
    for (int dir = 0; dir < 4; dir++) {
        
        // maze[currPos.first][currPos.second] = 0;
        // 도착했을 때
        if (currPos.first == mazeSize-1 && currPos.second == mazeSize-1) {
            cntRoute++;
            break;
        }

        else if (moveable(currPos, dir)) {
            // maze[currPos.first][currPos.second] = -1;
            findAllRoute(move_to(currPos, dir));
        }
    }

    // 이후 시행에서 이 곳을 들릴 수 있으니(최소 경로가 아니므로) 방문 표시를 지워주기
    maze[currPos.first][currPos.second] = 0;
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
bool moveable(pair<int, int> pos, int dir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];

    return x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 0;
}


pair<int, int> move_to(pair<int, int> pos, int dir)
{
    return pair<int, int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}
/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 *
 * @param infile ifstream
 */
void pullOneCase()
{
    ifstream infile("input5.txt");
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