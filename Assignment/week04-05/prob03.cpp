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

단어와 설명을 잘라서 저장하기보다 한 line으로 저장해서 필요할 때 잘라서 사용하는 게 나을 것 같다.
*/

/*
find_if() 함수
https://modoocode.com/263
*/
pair<string, string> split_line(string &line, char delimiter);

int main()
{
    vector<string> wordsAndDiscriptions;
    // vector<string> descriptions;
    string str;

    ifstream infile("shuffled_dict.txt");

    while (getline(infile, str))
    { // 1. 단어와 설명을 벡터에 저장
        wordsAndDiscriptions.push_back(str);
    }

    infile.close();

    // pair<string, string> p = split_line(wordsAndDiscriptions[0], '\t');
    // cout << p.first << ": " << p.second << endl;

    // find_if사용하여 한 라인에서 단어부분만 확인하는 코드 작성해보기
    cin >> str; // 2. 한 단어를 키보드로부터 입력받기

    auto it = find_if(wordsAndDiscriptions.begin(), wordsAndDiscriptions.end(), isExist);

    if (it != wordsAndDiscriptions.end())
    {
    }

    //     if (it != )
    //     for (auto it = wordsAndDiscriptions.begin(); it < wordsAndDiscriptions.end(); it++) {
    //         pair<string, string> p = split_line(*it, '\t');

    //         if (str == p.first) {                   // 3. 사전에 있는 단어면 그 단어와 설명 출력
    //             cout << p.first << ": " << p.second << endl;

    //             stringstream sstream(p.second);     // 4. 단어의 설명에 등장하는 길이가 3이상인 모든 단어들을 다시 사전에서 검색하여 단어와 설명을 출력 (동일 단어 2번 출력 X)
    //             string word;
    //             vector<string> duplication;
    //             while(sstream >> word) {
    //                 if
    //             }

    //             // break;
    //         }
    //     }

    //  auto it = find(word_list.begin(), word_list.end(), word);

    return 0;
}

/**
 * @brief 한 라인에서 단어와 설명을 나눠 pair 객체로 반환해주는 함수
 *
 * @param line 대상 라인
 * @param delimiter 구분자
 * @return pair<string, string> first: word, second: discription
 */
pair<string, string> split_line(string &line, char delimiter)
{
    stringstream sstream(line);
    string word, discription;

    getline(sstream, word, delimiter);
    getline(sstream, discription, delimiter);

    pair<string, string> wordAndDiscription = make_pair(word, discription);

    return wordAndDiscription;
}

bool isExist(string tmpStr)
{
    pair<string, string> p = split_line(tmpStr);
    return (p.first == str);
}