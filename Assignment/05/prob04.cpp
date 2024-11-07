#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;


/**
 * @brief 이미지 프린트 (debug용)
 * 
 * @param vec image vec
 * @param size image 크기
 */
void printImage(vector<vector<int>> vec, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << vec[i][j] << " ";
        }
        cout << '\n';
    }
}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 * 
 * @param infile ifstream
 * @param image 이미지를 담을 벡터
 * @param imageSize 이미지의 크기
 */
void pullOneCase(ifstream &infile, vector<vector<int>> &image,
                    int &imageSize) {
    infile >> imageSize;

    for (int i = 0; i < imageSize; i++) {
        vector<int> vec;
        for (int j = 0; j < imageSize; j++) {
            int element;
            infile >> element;
            vec.push_back(element);
        }
        image.push_back(vec);
    }
}

// x, y좌표 변화량 정의
int offset[8][2] {
    {-1, 0},    // 북
    {-1, 1},    // 북동
    {0, 1},     // 동
    {1, 1},     // 남동
    {1, 0},     // 남
    {1, -1},    // 남서
    {0, -1},    // 서
    {1, -1}    // 북서
};

bool moveable(pair<int, int> currPos, int dir,
                 vector<vector<int>> image, int imageSize) {
    int x = currPos.first + offset[dir][0];
    int y = currPos.second + offset[dir][1];

    return x >= 0 && x < imageSize &&
            y >= 0 && y < imageSize &&
            image[x][y] == 1;
}

// 컴포넌트 하나의 크기를 다 구했으면 무조건 startPoint로 올 것
void findComponentSize(pair<int, int> currPos) {

}

// 1. 1인 부분을 랜덤으로 선택한다. (시작점 찾기)
// 2. 인접한 곳을 다 찾는다.
// 3. 1인 부분을 다시 찾는다.
void solveProblem(vector<vector<int>> &image, int imageSize) {
    bool isSolved = false;
    while (!isSolved) {
        pair<int, int> currPos(0,0);
        bool getStartPoint = false;
        // 1인 곳에 시작 지점을 정한다.
        for (; currPos.first < imageSize; currPos.first++) {
            for (; currPos.second< imageSize; currPos.second++) {
                if (image[currPos.first][currPos.second] == 1) {
                    getStartPoint = true;
                    break;
                }
            }

            if (getStartPoint)
                break;
        }
        cout << "Current Position is (" << currPos.first << ", " 
                                    << currPos.second << ")" << endl;

        break;

        // 문제풀이 시작



        // 더 이상 시작 지점을 구할 수 없다면 (문제가 풀렸다면)
        if (!getStartPoint) {
            isSolved = true;
        }
    }
}




int main()
{
    ifstream infile("input.txt");
    int CASE;
    infile >> CASE;

    int imageSize;
    vector<vector<int>> image;

    pullOneCase(infile, image, imageSize);
    solveProblem(image, imageSize);
    // image.clear();
    // pullOneCase(infile, image, imageSize);

    infile.close();

    printImage(image, imageSize);

    
    return 0;
}
