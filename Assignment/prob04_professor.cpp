#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile("input4.txt");

    string word;            // 한 단어를 받는 변수 정의
    string words[1000];     // 단어들을 저장하는 변수 정의
    int words_count = 0;    // words 배열 내의 단어 개수
    //bool duplicated;

    while(infile>>word) {   //infile - while 은 이렇게 작성하자
        bool duplicated = false; // duplicated false, 변수는 사용할 때 선언, 스코프를 최대한 좁게 만들자
        // infile >> word;
        
        if (word.length() < 2)                       // 길이가 2 이상이 아닐 떄 다음 반복으로 넘어감
            continue;
        
        for (int i = 0; i < words_count; i++) {
            if (words[i] == word) {                  // 단어가 같을 시, duplicated = true     
                duplicated = true;
                break;
            }
        }

        if (duplicated == true)                     // 단어가 같을 시(duplicated = true), 다음 반복으로 넘어감
            continue;

        words[words_count++] = word;                  // 중복되지 않은 word를 words 배열에 추가


        // if (infile.eof() == false)                  // 너무 인덱스에 매몰되지 말자, eof 사용은 신중히!
        //     words_count++;                             
    }

    infile.close();
    
    for (int i = 0; i < words_count; i++) {
        cout << words[i];
        if (i != words_count)
            cout << endl;
    }
       
        
    return 0;
}
