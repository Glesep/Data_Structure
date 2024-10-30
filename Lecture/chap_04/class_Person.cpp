#include <iostream>
#include <string>

using namespace std;

class Person
{
/*
데이터 멤버인 name과 age를 private로 선언, 클래스 외부세어 접근할 수 없는 멤버들
*/
private:
    string name;
    int age;

/*
public 멤버는 클래스 외부에서 접근할 수 있는 멤버들이다.
*/
public:
    Person() {}
    Person(string name, int age) : name(name), age(age) {}
    void print()
    {
        cout << "Hi, my name is " << name << " and I am " << age        // 클래스 내부에서는 private 멤버들을 이용 가능
             << " years old." << endl;
    }
};


int main()
{
    Person person1("Alice", 30);
    person1.age = 20; // wrong  클래스 외부에서 private 사용
    person1.print();

    Person *ptr_person = new Person("Bob", 24);
    ptr_person->name = "Henry"; // wrong    클래스 외부에서 private 사용
    ptr_person->print();
    return 0;
}