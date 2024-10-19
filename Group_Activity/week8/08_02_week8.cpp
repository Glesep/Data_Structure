#include <iostream>
#include <cmath>
#include <list>
using namespace std;

bool same_integral_part(double first, double second)
{
    return int(first) == int(second);
}

struct is_near
{
    bool operator()(double first, double second)
    {   
        // fabs - 실수 절댓값 구하기
        return (fabs(first - second) < 5.0);
    }
};

int main()
{
    double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
                          12.77, 73.35, 72.25, 15.3,
                          72.25};

    list<double> mylist(mydoubles, mydoubles + 10);

    mylist.sort();
    mylist.unique();    // 전체 노드 데이터가 중복되지 않도록
    mylist.unique(same_integral_part);  // same_integral_part의 조건을 처음으로 만족하는 요소만 남기기
    mylist.unique(is_near());

    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    return 0;
}