#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

int groundSize = 0;
int after_K_years = 0;
vector<vector<int>> ground;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},
                    {0, 1},
                    {1, 0},
                    {0, -1}};

void pullOneCase();
void printGround(); // debug
void findMaxCount();
int countArea();

int main()
{

    pullOneCase();
    printGround();

    
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

/**
 * @brief 시작 위치를 찾으면 칸 수를 세어 기존 최대 칸 수와 비교
 * 
 */
void findMaxCount() {
    pair<int, int> pos_max;
    int count_max;

    for (int i = 0; i < groundSize; i++) {
        for (int j = 0; j < groundSize; j++) {
            if (ground[i][j] == 0) {
                pair<int, int> pos_current(i,j);
                // 칸 수 세기 시작 - 센 후에는 ground 초기화
                int count_current = countArea();
                pullOneCase();
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

int countArea() {
    int count_Area = 0;
    




    return count_Area;
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