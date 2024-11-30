#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void pullOneCase();
void printGround();

int groundSize = 0;
vector<vector<int>> ground;

// 방향 정의 배열
int offset[4][2] = {{-1, 0},  // 북
                    {0, 1},   // 동
                    {1, 0},   // 남
                    {0, -1}}; // 서
/*
포는 무조건 장애물을 하나만 넘어야 이동 가능
 */




int main()
{
    pullOneCase();
    printGround();
    
    return 0;
}

/*
한놈 넘긴 표시를 해야됨
*/

bool moveable(pair<int, int> currPos, pair<int, int> targetPos, int dir) {



}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 *
 * @param infile ifstream
 */
void pullOneCase()
{
    ifstream infile("input8.txt");
    infile >> groundSize;
    // 처음 불러올 때
    for (int i = 0; i < groundSize; i++)
    {
        vector<int> vec;
        for (int j = 0; j < groundSize; j++)
        {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        ground.push_back(vec);
    }

    infile.close();
}

/**
 * @brief ground 프린트 (debug용)
 */
void printGround()
{
    cout << groundSize << endl;

    for (int i = 0; i < groundSize; i++)
    {
        for (int j = 0; j < groundSize; j++)
        {
            cout << ground[i][j] << " ";
        }
        cout << '\n';
    }
}