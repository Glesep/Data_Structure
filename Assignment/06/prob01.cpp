#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int groundSize = 0;
int after_K_years = 0;
vector<vector<int>> ground;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},    // 북
                    {0, 1},     // 동
                    {1, 0},     // 남
                    {0, -1}};   // 서

void pullOneCase();
void printGround(); // debug
void findMaxCount();
int countArea(pair<int, int> curr);
bool moveable(pair<int,int> pos, int dir);
pair<int,int> move_to(pair<int,int> pos, int dir);

int main()
{

    pullOneCase();
    findMaxCount();

    // printGround();

    
    return 0;
}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 * 
 * @param infile ifstream
 */
void pullOneCase() {
    ifstream infile("input1.txt");
    infile >> groundSize;

    for (int i = 0; i < groundSize; i++) {
        vector<int> vec;
        for (int j = 0; j < groundSize; j++) {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        ground.push_back(vec);
    }

    infile >> after_K_years;

    infile.close();
}

bool moveable(pair<int,int> pos, int dir)
{
    int x = pos.first + offset[dir][0];
    int y = pos.second + offset[dir][1];
    return x >= 0 && x < groundSize && y >= 0 && y < groundSize && ground[x][y] == 0;   // 0이 길 이라는 표시
}

pair<int,int> move_to(pair<int,int> pos, int dir)
{
    return pair<int,int>(pos.first + offset[dir][0], pos.second + offset[dir][1]);
}

/**
 * @brief 시작 위치를 찾으면 칸 수를 세어 기존 최대 칸 수와 비교
 * 
 */
void findMaxCount() {
    pair<int, int> pos_max;
    int count_max = 0;

    for (int i = 0; i < groundSize; i++) {
        for (int j = 0; j < groundSize; j++) {
            if (ground[i][j] == 0) {
                pair<int, int> pos_current(i,j);
                // 칸 수 세기 시작 - 센 후에는 ground 초기화
                int count_current = countArea(pos_current);
                pullOneCase();
                cout << "reset" << endl;
                printGround();
                // 센 칸 수와 기존 최대 칸 수 비교
                    // 바꿔야되면 바꿔주기
                if (count_current > count_max) {
                    count_max = count_current;
                    pos_max = pos_current;
                }
            }
            // 
        }
    }

    cout << pos_max.first << " " << pos_max.second << endl;
    cout << count_max << endl;
}

int countArea(pair<int, int> curr) {
    int count_area = 1;
    queue<pair<int, int>> que;
    ground[curr.first][curr.second] = -1;
    que.push(curr);

    while(after_K_years > 0) {
        curr = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            if (moveable(curr, dir)) {
                pair<int, int> p = move_to(curr, dir);
                ground[p.first][p.second] = ground[curr.first][curr.second] - 1;
                count_area++;
                que.push(p);
            }
        }

        after_K_years--;
    }
    printGround();
    // cout << count_area << endl;



    return count_area;
}


/**
 * @brief 이미지 프린트 (debug용)
 */
void printGround() {
    cout << groundSize << endl;

    for (int i = 0; i < groundSize; i++) {
        for (int j = 0; j < groundSize; j++) {
            cout << ground[i][j] << " ";
        }
        cout << '\n';
    }

    cout << after_K_years << endl;
}