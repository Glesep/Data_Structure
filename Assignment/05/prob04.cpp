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

void solveProblem(vector<vector<int>> &image, int imageSize) {
    bool isSolved = false;
    while (!isSolved) {
        int i, j;
        bool getStartPoint = false;
        // 1인 곳에 시작 지점을 정한다.
        for (i = 0; i < imageSize; i++) {
            for (j = 0; j < imageSize; j++) {
                if (image[i][j] == 1) {
                    getStartPoint = true;
                    break;
                }
            }

            if (getStartPoint)
                break;

            
        }


        // 더 이상 시작 지점을 구할 수 없다면 (문제가 풀렸다면)
        if (!getStartPoint) {
            isSolved = true;
        }
    }



}



// 1. 1인 부분을 랜덤으로 선택한다. (시작점 찾기)
// 2. 인접한 곳을 다 찾는다.
// 3. 1인 부분을 다시 찾는다.
int main()
{
    ifstream infile("input.txt");
    int CASE;
    infile >> CASE;

    int imageSize;
    vector<vector<int>> image;

    pullOneCase(infile, image, imageSize);
    image.clear();
    pullOneCase(infile, image, imageSize);

    infile.close();

    printImage(image, imageSize);

    
    return 0;
}
