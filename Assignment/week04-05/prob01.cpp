#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
1. 키보드로부터 문자열 입력받기
2. 사용자가 exit 입력 시, 프로그램 종료
3. 단어 입력 시
    1. 목록에 단어가 없으면 추가
    2. 목록에 단어가 있으면 삭제
4. 입력 시, 매번 단어의 목록을 한 줄로 출력, 단어들은 정렬되어있어야 함
 */
int main()
{   
    vector<string> word_list;       // 단어 리스트 정의

    while (1){
        string word;
        cin >> word;            // 1. 키보드로부터 문자열 입력받기

        if (word == "exit") {   // 2. 사용자가 exit 입력 시, 프로그램 종료
            break;
        }

        auto it = find(word_list.begin(), word_list.end(), word);

        // 3-1. 단어 입력 시 목록에 단어가 없으면 추가 후 정렬
        if (it == word_list.end()) {
            word_list.push_back(word);
            sort(word_list.begin(), word_list.end());
        }

        // 3-2. 단어 입력 시, 목록에 단어가 있으면 삭제
        else {
            it = word_list.erase(it);
        }

        // 4. 단어의 목록을 한 줄로 출력
        for (auto i : word_list)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}
