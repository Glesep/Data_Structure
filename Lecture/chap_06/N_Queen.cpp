#include <iostream>
#include <cmath>
using namespace std;


/**
 * @brief 앞의 말들 간에는 충돌이 없음이 보장, 마지막에 놓인 말이 그 이전에 놓인 말들과 충돌하는가 검사
 * 
 * @param level 몇번째 행인지 알려주는 매개변수
 * @return true 
 * @return false 
 */
bool promising(int level)
{
    for (int i = 1; i < level; i++)
    {
        if (cols[i] == cols[level])
            return false;
        else if (level - i == abs(cols[level] - cols[i]))
            return false;
    }
    return true;
}

int cols[N + 1];

bool queens(int level)
{
    if (!promising(level))  // 불가할 때 바로 false
        return false;

    else if (level == N)    // 찾았을때
    {
        for (int i = 1; i <= N; i++)
            printf("(%d, %d)", i, cols[i]);
        return true;
    }
    
    for (int i = 1; i <= N; i++)    // 일반적 case, 다음 레벨에 1~N까지 넣어보고 되는지 확인
    {
        cols[level + 1] = i;
        if (queens(level + 1))
            return true;
    }
    return false;
}