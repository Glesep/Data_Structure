#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;




vector<vector<int>> image; // image가 담길 2차원 벡터
int imageSize;  // image의 크기


/**
 * @brief 이미지 프린트 (debug용)
 */
void printImage() {
    for (int i = 0; i < imageSize; i++) {
        for (int j = 0; j < imageSize; j++) {
            cout << image[i][j] << " ";
        }
        cout << '\n';
    }
}

/**
 * @brief 하나의 테스트 케이스를 불러오는 함수
 * 
 * @param infile ifstream
 */
void pullOneCase(ifstream &infile) {
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
// a - b = 4
// b - a = 4
int offset[8][2] {
    {-1, 0},    // 북 0
    {-1, 1},    // 북동 1
    {0, 1},     // 동 2
    {1, 1},     // 남동 3
    {1, 0},     // 남 4
    {1, -1},    // 남서 5
    {0, -1},    // 서 6
    {1, -1}    // 북서 7
};

bool moveable(pair<int, int> currPos, int dir) {
    int x = currPos.first + offset[dir][0];
    int y = currPos.second + offset[dir][1];

    return x >= 0 && x < imageSize &&
            y >= 0 && y < imageSize &&
            image[x][y] == 1;
}

pair<int, int> move_to(pair<int, int> currPos, int dir, stack<int> oppositeDirStack)
{
    pair <int, int> nextPos (currPos.first + offset[dir][0],
                            currPos.second + offset[dir][1]);

    oppositeDirStack.push(abs(dir - 4)); // 움직인 방향의 반대 방향을 stack에 저장한다.
    return nextPos;
}

void moveWithinComponent(pair<int, int> currPos, int &componentSize, stack<int> oppositeDirStack) {
    for (int dir = 0; dir < 8; dir++) {
        // 갈수 있는 방향의 반대방향을 넣고 재귀함수
        if (moveable(currPos, dir)) {
            currPos = move_to(currPos, dir, oppositeDirStack);
            moveWithinComponent(currPos, componentSize, oppositeDirStack);
        }

        
        
    }
}
// 1. 갈수 있는 방향을 찾는다.
// 2. 찾았으면 바로 가면서 반대방향을 스택에 넣는다.
// 3. 위를 재귀함수로 반복한다.
// 4. 갈 수 잇는 방향이 없으면 스택에 저장해놓은 방향으로 간다.


// 컴포넌트 하나의 크기를 다 구했으면 무조건 startPoint로 올 것
void findComponentSize(pair<int, int> currPos, stack<int> dirStack) {
    // startPoint 정의
    pair<int, int> startPos = currPos;
    // 방문하였으면 1 증가 (startPoint)
    image[currPos.first][currPos.second]++;
    int componentSize = 1;


    // ============== 아래부터 재귀함수 ============== 


    

    
}

// 1. 1인 부분을 랜덤으로 선택한다. (시작점 찾기)
// 2. 인접한 곳을 다 찾는다.
// 3. 1인 부분을 다시 찾는다.
void solveProblem() {
    bool isSolved = false;
    while (!isSolved) {
        pair<int, int> startPos(0,0);
        bool getStartPoint = false;
        // 1인 곳에 시작 지점을 정한다.
        for (; startPos.first < imageSize; startPos.first++) {
            for (; startPos.second< imageSize; startPos.second++) {
                if (image[startPos.first][startPos.second] == 1) {
                    getStartPoint = true;
                    break;
                }
            }

            if (getStartPoint)
                break;
        }
        cout << "Current Position is (" << startPos.first << ", " 
                                    << startPos.second << ")" << endl;

        break;

        // 문제풀이 시작
        // findComponentSize



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


    pullOneCase(infile);
    solveProblem();
    // image.clear();
    // pullOneCase(infile, image, imageSize);

    infile.close();

    printImage();

    
    return 0;
}
