#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
1. 단어와 설명을 벡터에 저장
2. 한 단어를 키보드로부터 입력받기
3. 사전에 있는 단어면 그 단어와 설명 출력
4. 단어의 설명에 등장하는 길이가 3이상인 모든 단어들을 다시 사전에서 검색하여 단어와 설명을 출력 (동일 단어 2번 출력 X)


** dictionary 자료구조 사용해보기 - map(데이터들 간 순서정렬이 자동으로)
** 중복제거에 set 자료구조 사용해보기
** if(getline(ss,word,'\t') && getline(ss, def)) - 아이디어 얻어가기
** remove_if 알아보기 - unique와 비슷함
** 간단한 기능을 이용해 위의 함수들의 역할을 하는 코드 짜보는게 중요하다.
*/

void store_wordsAndDiscriptions(string &line, vector<string> &words, vector<string> &discriptions);

int main()
{
    vector<string> words;
    vector<string> discriptions;
    string str;

    ifstream infile("shuffled_dict.txt");

    while (getline(infile, str))
    { // 1. 단어와 설명을 벡터에 저장
        store_wordsAndDiscriptions(str, words, discriptions);
    }

    infile.close();

    cin >> str; // 2. 한 단어를 키보드로부터 입력받기

    for (int i = 0; i < (int)words.size() - 1; i++) {
        if (str == words[i]) {
            cout << words[i] << ": " << discriptions[i] << endl;    // 3. 사전에 있는 단어면 그 단어와 설명 출력

            stringstream sstream(discriptions[i]);
            string token;
            vector<string> duplicatedList;
            while (sstream >> token) {
                // 4. 단어의 설명에 등장하는 길이가 3이상인 모든 단어들을 다시 사전에서 검색하여 단어와 설명을 출력 (동일 단어 2번 출력 X)
                if (token.length() >= 3 && find(duplicatedList.begin(), duplicatedList.end(), token) == duplicatedList.end()) {
                    for (int j = 0; j < (int)words.size() - 1; j++) {
                        if (token == words[j]) {
                            cout << words[j] << ": " << discriptions[j] << endl;
                            duplicatedList.push_back(words[j]);
                        }
                    }
                }
            }

            break;  // 찾았으니 반복 종료
        }
    }

    return 0;
}

/**
 * @brief 한 라인에서 단어와 설명을 나눠서 vector에 저장하는 함수
 * 
 * @param line split할 라인
 * @param words 단어가 저장될 벡터
 * @param discriptions 설명이 저장될 벡터
 */
void store_wordsAndDiscriptions(string &line, vector<string> &words, vector<string> &discriptions) {
    stringstream sstream(line);
    string tmp;

    getline(sstream, tmp, '\t');
    words.push_back(tmp);

    getline(sstream, tmp, '\t');
    discriptions.push_back(tmp);
}
