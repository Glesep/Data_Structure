#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int groundSize = 0;
int after_K_years = 0;
vector<vector<int>> ground;
bool resetData = false;

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
    // ground를 리셋할 때
    if (resetData) {
        for (int i = 0; i < groundSize; i++) {
            for (int j = 0; j < groundSize; j++) {
                infile >> ground[i][j];
            }
        }
    }

    // 처음 불러올 때
    else {
        for (int i = 0; i < groundSize; i++) {
            vector<int> vec;
            for (int j = 0; j < groundSize; j++) {
                int element;
                infile >> element;
                vec.push_back(element);
            }
            ground.push_back(vec);
        }
        resetData = true;
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
                // 칸 수 세기 시작
                int count_current = countArea(pos_current);
                pullOneCase();  // ground 초기화
                // 센 칸 수와 기존 최대 칸 수 비교
                    // 바꿔야되면 바꿔주기
                if (count_current > count_max) {
                    count_max = count_current;
                    pos_max = pos_current;
                }
            } 
        }
    }

    cout << pos_max.first << " " << pos_max.second << endl;
    cout << count_max << endl;
}

/**
 * @brief 현재 위치에 풀을 심었을 때 k년 뒤 풀이 자라는 구역의 개수를 반환하는 함수
 * 
 * @param curr 현재 위치
 * @return int 풀이 자라는 구역의 개수 반환
 */
int countArea(pair<int, int> curr) {
    int count_area = 0;
    queue<pair<int, int>> que;
    bool END = false;
    ground[curr.first][curr.second] = 0;
    que.push(curr);

    // 반복 중단 조건에 걸리거나 que가 빌 때까지 반복
    while(!END && !que.empty()) {
        curr = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            if (moveable(curr, dir)) {
                pair<int, int> p = move_to(curr, dir);
                ground[p.first][p.second] = ground[curr.first][curr.second] - 1;

                // 반복 중단 조건: k+1년의 경우를 구하려 했을 때
                if (ground[p.first][p.second] < (-1 * after_K_years)) {
                    END = true;
                    break;
                }

                count_area++;
                que.push(p);
            }
        }
    }
    return count_area;
}

/**
 * @brief ground 프린트 (debug용)
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