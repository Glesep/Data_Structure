#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;
int maze[MAX_SIZE][MAX_SIZE];
int n;

int offset[4][2] = {{-1, 0},
                    {0, 1},
                    {1, 0},
                    {0, -1}};

void read_maze()
{
    ifstream mazefile("maze.txt");
    mazefile >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mazefile >> maze[i][j];
        }
    }
    mazefile.close();
}

void print_maze()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

bool movable(pair<int,int> pos, int dir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0;   // 0이 길 이라는 표시
}

pair<int,int> move_to(pair<int,int> pos, int dir)
{
    return pair<int,int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}

int main()
{
    read_maze();
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
            if (movable(cur, dir))
            {
                pair<int, int> p = move_to(cur, dir);
                maze[p.first][p.second] = maze[cur.first][cur.second] - 1;
                if (p.first == n - 1 && p.second == n - 1)
                {
                    cout << "Found the path." << endl;
                    print_maze();
                    return 0;
                }
                que.push(p);
            }
        }
    }
    cout << "No path exists." << endl;
    return 0;
}