#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

typedef struct {                        // Point2D 구조체 정의
    double x, y;
} Point2D;

Point2D *makeArray(ifstream &infile);
double findMaxLength(Point2D *points, int countPoints, Point2D *firstPoint_Max, Point2D *secondPoint_Max);


int main() {

    ifstream infile("input2.txt");          // 파일 불러오기

    int countPoints;
    infile >> countPoints;                  // 점의 개수 변수에 저장
    
    ifstream &inFile = infile;              // 참조 사용
    Point2D *points = makeArray(inFile);    // stream은 복사가 불가능한 객체 - 참조로 매개변수 사용
    
    infile.close();


    Point2D firstPointMax = *(points), secondPointMax = *(points);  // 최대 길이일 때의 두 좌표



    double maxLength = findMaxLength(points, countPoints, &firstPointMax, &secondPointMax);



    // 결과 출력
    cout << firstPointMax.x << " " << firstPointMax.y << endl;
    cout << secondPointMax.x << " " << secondPointMax.y << endl;
    cout << maxLength << endl;

    // ========================================================================================
    // garbage 삭제
    delete[] points;
    
    return 0;
}


/**
 * @brief 점의 좌표를 배열로 받는 함수
 * 
 * @param array 좌표들이 저장될 배열의 주소 (포인터 타입)
 * @param infile ifstream 변수(참조로만 가능)
 * @return Point2D* 좌표들이 저장된 배열의 주소
 */
Point2D *makeArray(ifstream &inFile) {
    // 좌표 개수는 이미 저장된 상태

    int arraySize = 4;                              // 초기 배열 크기 정의
    Point2D *array = new Point2D[arraySize];        // 동적 생성된 길이가 4인 배열 정의

    int index = 0;                                  // index 표현 변수 정의

    // 파일 내용을 다 읽을 때까지 반복
    while(inFile) {
        /* 배열 array의 크기가 부족할 떄 */
        if (index==arraySize) {
            arraySize *= 2;
            Point2D *tmp = new Point2D[arraySize];

            for (int i = 0; i < index; i++) {
                *(tmp+i) = *(array+i);
            }

            delete[] array;
            array = tmp;
        }

        int tmpX, tmpY;

        inFile >> tmpX;                             // x좌표 저장
        (array+index)->x = tmpX;

        inFile >> tmpY;                             // y좌표 저장
        (array+index)->y = tmpY;                    

        index++;                                    // index 1 추가
    }


    return array;
}

/**
 * @brief 
 * 
 * @param points 파일에 있는 점들의 좌표들을 기록한 배열을 가리키는 포인터
 * @param countPoints 좌표 개수
 * @param firstPoint_Max 길이가 최대일 때의 첫 번째 점의 좌표 변수의 주소
 * @param secondPoint_Max 길이가 최대일 때의 두 번째 점의 좌표 변수의 주소
 * @return double 최대 길이 반환
 */
double findMaxLength(Point2D *points, int countPoints, Point2D *firstPoint_Max, Point2D *secondPoint_Max) {
    double maxLength = 0;
    double length = 0;
    for (int i = 0; i < countPoints; i++) {
        for (int j = i+1; j < countPoints; j++) {
            length = sqrt(pow(((points+i)->x - (points+j)->x), 2) + pow(((points+i)->y - (points+j)->y), 2));       // 각 좌표의 길이 구하기

            if (length > maxLength) {       // 길이 최댓값, 좌표 재설정
                *firstPoint_Max = *(points+i);
                *secondPoint_Max = *(points+j);

                maxLength = length;
            }
        }
    }

    return maxLength;
}