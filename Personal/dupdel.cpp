#include <vector>
#include <iostream>
using namespace std;

vector<int> removeDuplicatesRecursive(vector<int> &vec, int currentIndex = 0)
{
    // 기저 조건: 벡터의 끝에 도달했을 때
    if (currentIndex >= vec.size())
    {
        return vec;
    }

    // 현재 원소부터 끝까지 검사하면서 중복 제거
    for (int i = currentIndex + 1; i < vec.size();)
    {
        if (vec[currentIndex] == vec[i])
        {
            // 중복된 원소 제거
            vec.erase(vec.begin() + i);
        }
        else
        {
            i++;
        }
    }

    // 다음 원소로 재귀 호출
    return removeDuplicatesRecursive(vec, currentIndex + 1);
}
