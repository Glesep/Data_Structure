#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("input4.txt");

    string word;            // 한 단어를 받는 변수 정의
    string words[1000];     // 포인터 배열으로 단어들을 저장하는 변수 정의
    int words_index = 0;    // words 배열의 최고 인덱스
    bool duplicated;

    while(infile) {
        duplicated = false; // duplicated false
        infile >> word;
        
        if (word.length() < 2)                       // 길이가 2 이상이 아닐 떄 다음 반복으로 넘어감
            continue;
        
        for (int i = 0; i <= words_index; i++) {
            if (words[i] == word) {                  // 단어가 같을 시, duplicated = true     
                duplicated = true;
                break;
            }
        }

        if (duplicated == true)                     // 단어가 같을 시(duplicated = true), 다음 반복으로 넘어감
            continue;

        words[words_index] = word;                  // 중복되지 않은 word를 words 배열에 추가
        words_index++;                              
    }

    infile.close();
    
    for (int i = 0; i <= words_index; i++) {
        cout << words[i];
        if (i != words_index)
            cout << endl;
    }
       
        
    return 0;
}
