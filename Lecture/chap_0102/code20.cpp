#include <iostream>
#include <vector>
#include <string>

using namespace std;
// vector에서 원소의 삽입을 생각해보자

int main()
{
    vector<string> sentence{"how", "is", "programming"};

    // First try
    sentence[1] = "fun"; // 삽입된 것이 아니라

    for (auto word : sentence)
        cout << word << " ";
    cout << endl;

    // Second try
    sentence[1] = "is"; // 벡터 sentence를 원래로 되돌린다.
    // 배열에서 처럼 한 칸씩 뒤로 옮긴다.
    sentence[3] = sentence[2]; // sentence[3]은 인덱스의 범위를 넘어서므로 좋지않음
    sentence[2] = sentence[1];
    sentence[1] = "fun";

    for (auto word : sentence)
        cout << word << " ";
    cout << endl;

    // Third try
    vector<string> sentence2{"how", "is", "programming"};
    sentence2.at(3) = sentence2.at(2);
    sentence2.at(2) = sentence2.at(1);
    sentence2.at(1) = "fun";
    for (auto word : sentence2)
        cout << word << " ";
    cout << endl;

    // Fourth try
    vector<string> sentence3{"how", "is", "programming"};       // 벡터는 저장된 값과 실제 벡터의 크기가 같을 때 좋은 사용법이라 할 수 있다.
    sentence3.resize(4);    // 벡터의 크기를 4로 만들어준다.
    for (int i = sentence3.size() - 2; i >= 1; i--)
        sentence3.at(i + 1) = sentence3.at(i);
    sentence3.at(1) = "fun";
    for (auto word : sentence3)
        cout << word << " ";
    cout << endl;


    return 0;
}
