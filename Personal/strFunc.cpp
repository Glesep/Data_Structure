#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "hello";
    string str2 = "C++";
    string str3 = "world";


    // str.at(index), str[index] : str의 index에 해당하는 요소 반환
    cout << str1.at(1) << endl;     // e
    cout << str1[1] << endl;        // e
    cout << '\n';

    // str.append(n, ch) : str 뒤에 n개의 char타입 요소를 붙이기, ch는 변수, 상수 가능 
    str1.append(3,'o');             
    cout << str1 << endl;           // helloooo
    cout << '\n';


    str1 = "hello";
    char tmp1 = 'o';
    str1.append(3,tmp1);
    cout << str1 << endl;           // helloooo
    cout << '\n';

    // str.append(strTmp) :  str 뒤에 strTmp를 붙이기, strTmp는 string타입
    str1 = "hello";
    string tmp2 = " newbie";
    str1.append(tmp2);
    cout << str1 << endl;           // hello newbie
    cout << '\n';

    // str.clear() : str 내 요소 전체 삭제
    // str.empty() : str 내부가 비었으면 true, 아니면 false
    str1.clear();
    cout << str1.length() << endl;      // 0
    cout << str1.empty() << endl;       // 1(true)
    cout << '\n';

    /*
    str.compare(strTmp) : str - strTmp 생각
    사전식으로 str이 앞서면 -1, 같으면 0 strTmp가 앞서면 1
    사전식으로 대문자가 더 앞섬
    */
    str1 = "hello";
    cout << str1.compare(str2) << endl; // 1
    cout << '\n';

    /*
    str.erase() : str 내 전체 문자 삭제
    str.erase(pos, n) : str의 pos 인덱스부터 n개 문자 삭제
    */

    str1.erase();
    cout << str1.length() << endl;  // 0
    cout << str1.empty() << endl;   // 1
    cout << '\n';

    str2.erase(1, 2);
    cout << str2 << endl;           // C
    cout << '\n';

    str1 = "hello";
    str2 = "C++";

    /*
    str.find(strTmp) : str 내에서 strTmp가 존재할 때, strTmp가 시작되는 첫번째 인덱스 반환 
    str.find(strTmp, pos) : str.find를 "pos인덱스부터" 찾음
    */

    cout << str1.find("l") << endl; // 2
    cout << str1.find("l", 3) << endl;  // 3
    cout << '\n';

    /*
    str.find_first_of(strTmp, pos) : str에서 strTmp 문자열에 있는 문자 중
                        가장 먼저 등장하는 문자의 인덱스를 반환 (str의 pos 인덱스부터 찾음)

    str.find_first_not_of(strTmp, pos) : str에서 strTmp 내에 있는 문자가 아닌 문자가
                            가장 먼저 등장하는 인덱스를 반환 (str의 pos 인덱스부터 찾음)

    pos 생략시 처음부터 찾음
    */

    cout << str1.find_first_of("hl") << endl;   // 0
    cout << str1.find_first_not_of("hl") << endl;   // 1
    cout << '\n';





    
    return 0;
}
