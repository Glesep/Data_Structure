#include <iostream>
#include <fstream>
using namespace std;

typedef struct {                        // Point2D 구조체 정의
    double x, y;
} Point2D;

void makeArray(Point2D point, Point2D *array);

int main() {
    ifstream infile("input2.txt");          // 파일 불러오기
    int countPoints;
    infile >> countPoints;                  // 점의 개수 변수에 저장
    
    int *array = new int[4];                // 동적 생성된 길이가 4인 배열
    
    cout << sizeof(array)/sizeof(int);

    












    infile.close();
    
    return 0;
}


// void makeArray(Point2D point, Point2D *array) {

//     /* 배열 array의 크기가 부족할 떄 */
//     int *tmp = (int *)malloc(8*sizeof(int));        // 전의 크기의 2배로 크기 설정

//     for (int i=0; i<4; i++)
//         tmp[i] = array[i];
    
//     free(array);                                    // 기존의 배열이 있는 메모리를 삭제
//     array = tmp;
// }
