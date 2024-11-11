#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
const int MAX_SIZE = 100;

const int PATH = 0;        // 지나갈 수 있는 위치
const int WALL = 1;        // 지나갈 수 없는 위치
const int VISITED = 2;     // 이미 방문한 위치
const int BACKTRACKED = 3; // 방문했다가 되돌아 나온 위치

int maze[MAX_SIZE][MAX_SIZE];
int n; // 미로의 크기

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

struct Position
{
    int x, y;
    Position() {}
    Position(int x, int y) : x(x), y(y) {}
};

int offset[4][2] = {{-1, 0},
                    {0, 1},
                    {1, 0},
                    {0, -1}};

bool movable(Position pos, int dir)
{
    int x = pos.x + offset[dir][0];
    int y = pos.y + offset[dir][1];
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == PATH;
}
Position move_to(Position pos, int dir)
{
    return Position(pos.x + offset[dir][0], pos.y + offset[dir][1]);
}

int main()
{
    read_maze();
    stack<Position> s;
    Position cur(0, 0);
    while (true)
    {
        maze[cur.x][cur.y] = VISITED;
        
        if (cur.x == n - 1 && cur.y == n - 1)
        { 
            cout << "Found the path." << endl;
            break;
        }
        bool forwarded = false;
        
        for (int dir = 0; dir < 4; dir++)
        {
            if (movable(cur, dir))
            {
                s.push(cur);
                cur = move_to(cur, dir);
                forwarded = true;
                break;
            }
        }
        if (!forwarded)
        {
            maze[cur.x][cur.y] = BACKTRACKED;
            if (s.empty())
            {
                cout << "No path exists" << endl;
                break;
            }
            cur = s.top(), s.pop();
        }
        
    }
    print_maze();
}