#include <iostream>
#include <fstream>
using namespace std;

typedef struct {                        // Point2D 구조체 정의
    double x, y;
} Point2D;

Point2D makeArray(Point2D point, Point2D *array, int *arraySize);

int main() {
    ifstream infile("input2.txt");          // 파일 불러오기
    int countPoints;
    infile >> countPoints;                  // 점의 개수 변수에 저장
    

    
    

    












    infile.close();
    




    // =============================================================
    // garbage 삭제
    delete[] array;
    


    return 0;
}

/**
 * @brief 점의 좌표를 배열로 받는 함수
 * 
 * @param point 점의 좌표
 * @param array 좌표들이 저장될 배열의 주소 (포인터 타입)
 * @param infile ifstream 변수
 * @return Point2D* 좌표들이 저장된 배열의 주소
 */
Point2D *makeArray(Point2D point, Point2D *array, ifstream infile) {

    int arraySize = 4;                              // 초기 배열 크기 정의
    Point2D *array = new Point2D[arraySize];        // 동적 생성된 길이가 4인 배열

    int index = 0;                                  // index 표현 변수 정의

    // 파일 내용을 다 읽을 때까지 반복
    while(infile) {

        if (index==arraySize) {
            arraySize *= 2;
            Point2D *tmp = new Point2D[arraySize];
        }




        /* 배열 array의 크기가 부족할 떄 */
        if (*(array+3) == )
        Point2D *tmp = new Point2D((*arraySize)*2];        // 전의 크기의 2배로 크기 설정

        for (int i=0; i<4; i++)
            *(tmp+i) = *(array+i);
        
        free(array);                                    // 기존의 배열이 있는 메모리를 삭제
        array = tmp;

    }


    return array;

}
