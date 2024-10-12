#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Term
{
    int coef;
    int expo;
    Term *next = nullptr;

    // default 생성자
    Term() {}

    // 생성자
    Term(int c, int e) : coef(c), expo(e) {}
    Term(int c, int e, Term *p) : coef(c), expo(e), next(p) {}
};

struct Polynomial
{
    char name;
    Term *first = nullptr;
    int size = 0;

    // default 생성자
    Polynomial() {}
    // 생성자
    Polynomial(char name) : name(name) {}
};

vector<Polynomial> polys;

void add_term(Polynomial &poly, int c, int e);
vector<Polynomial>::iterator find_poly(char name);
void print_term(Term *pTerm);
void print_poly(Polynomial &p);
void handle_print(char name);
int calc_term(Term *term, int x);
int calc_poly(Polynomial poly, int x);
void handle_calc(char name, int x);
void insert_polynomial(Polynomial p);
void handle_add(char name, int c, int e);
void clear_poly(Polynomial &p);
void add_poly(char h, char p, char q);
void multiplypoly(char p, char q, char r);

int main()
{
    string command, arg1, arg2, arg3;
    while (1)
    {
        cout << "$ ";
        cin >> command;
        if (command == "print")
        {
            cin >> arg1;
            handle_print(arg1[0]);
        }
        else if (command == "calc")
        {
            cin >> arg1 >> arg2;
            handle_calc(arg1[0], stoi(arg2));
        }
        else if (command == "define")
        {
            cin >> arg1;
            Polynomial pol(arg1[0]);
            insert_polynomial(pol);
        }
        else if (command == "add")
        {
            cin >> arg1 >> arg2 >> arg3;
            handle_add(arg1[0], stoi(arg2), stoi(arg3));
        }
        else if (command == "addpoly")
        {
            cin >> arg1 >> arg2 >> arg3;
            add_poly(arg1[0], arg2[0], arg3[0]);
        }
        else if (command == "multiplypoly")
        {
            cin >> arg1 >> arg2 >> arg3;
            multiplypoly(arg1[0], arg2[0], arg3[0]);
        }
        else if (command == "exit")
            break;
    }
}

//==========================================================================================

/**
 * @brief
 * 다항식 poly에 새로운 하나의 항을 추가하는 함수
 * 1. 추가하려는 항과 동일한 차수의 항이 이미 있는 경우: 기존 항의 계수만 변경
 * 2. 그렇지 않은 경우: 새로운 항을 삽입
 * @param poly 해당 다항식 (참조)
 * @param c 추가하고 싶은 항의 계수
 * @param e 추가하고 싶은 항의 차수
 */
void add_term(Polynomial &poly, int c, int e)
{
    // 계수가 0인 경우
    if (c == 0)
        return;

    // poly.first == head
    Term *p = poly.first, *q = nullptr;

    while (p != nullptr && p->expo > e)
    {
        q = p;
        p = p->next;
    }

    // 동일 차수의 항이 존재하는 경우
    if (p != nullptr && p->expo == e)
    {
        // 계수 더하기
        p->coef += c;
        // 만약 계수가 0이 됐다면
        if (p->coef == 0)
        {
            // 첫 번째 노드일 때
            if (q == nullptr)
                poly.first = p->next;
            // 일반적 경우일 때
            else
                q->next = p->next;

            poly.size--;
            delete p;
        }

        return;
    }

    // 새로운 차수의 항을 삽입하는 경우
    if (q == nullptr) // while문을 안 돌았을 경우 - empty list 거나 차수가 가장 높거나 - 맨 앞에 삽입
        poly.first = new Term(c, e, poly.first);
    else // q의 뒤에, p의 앞에 삽입 - p == nullptr 가능
        q->next = new Term(c, e, p);

    poly.size++;
}

// 다항식을 찾는 함수
vector<Polynomial>::iterator find_poly(char name)
{
    for (auto it = polys.begin(); it != polys.end(); it++)
    {
        if (it->name == name)
            return it;
    }

    return polys.end();
}

void print_term(Term *pTerm)
{
    cout << pTerm->coef;
    if (pTerm->expo != 0)
        cout << "x^" << pTerm->expo;
}

void print_poly(Polynomial &p)
{
    cout << p.name << " = ";
    Term *t = p.first;
    while (t != nullptr)
    {
        print_term(t);
        if (t->next != nullptr && t->next->coef > 0)
            cout << "+";
        t = t->next;
    }
    cout << endl;
}

void handle_print(char name)
{
    auto it = find_poly(name);
    if (it == polys.end())
        cout << "No such polynomial exists." << endl;
    else
        print_poly(*it);
}

int calc_term(Term *term, int x)
{
    int result = term->coef;
    for (int i = 0; i < term->expo; i++)
    {
        // 계수 * x에 들어간 값
        result *= x;
    }
    return result;
}

int calc_poly(Polynomial poly, int x)
{
    int result = 0;
    Term *t = poly.first;
    // 다항식을 순회
    while (t != nullptr)
    {
        result += calc_term(t, x);
        t = t->next;
    }

    return result;
}
void handle_calc(char name, int x)
{
    auto it = find_poly(name);
    if (it == polys.end())
        cout << "No such polynomial exists." << endl;
    else
        cout << calc_poly(*it, x) << endl;
}

void insert_polynomial(Polynomial p)
{
    auto it = find_poly(p.name);

    if (it == polys.end())
    {
        polys.push_back(p);
    }

    else
    {
        // 동일한 이름의 다항식이 존재했을 시, 기존 다항식을 삭제 후 새 다항식을 넣어줌
        clear_poly(*it);
        *it = p;
    }
}

void handle_add(char name, int c, int e)
{
    auto it = find_poly(name);
    if (it == polys.end())
    {
        cout << "No such polynomial exists." << endl;
        return;
    }

    add_term(*it, c, e);
}

void clear_poly(Polynomial &p)
{
    Term *t = p.first, *tmp;

    while (t != nullptr)
    {
        tmp = t; // 알맹이는 남기기 위해 tmp 정의
        t = t->next;
        delete tmp;
    }
    p.first = nullptr;
}

/**
 * @brief 매개변수로 받은 두 다항식을 더한 결과를 리턴해주는 함수
 *
 * @param p
 * @param q
 * @return Polynomial
 */

void add_poly(char h, char p, char q)
{
    Polynomial result(h);

    auto it_p = find_poly(p);
    auto it_q = find_poly(q);

    Term *t = it_p->first;
    while (t != nullptr)
    {
        add_term(result, t->coef, t->expo);
        t = t->next;
    }

    t = it_q->first;
    while (t != nullptr)
    {
        add_term(result, t->coef, t->expo);
        t = t->next;
    }

    if (result.first == nullptr)
    {
        cout << "error!" << endl;
    }
    else
        insert_polynomial(result);
}

void multiplypoly(char p, char q, char r)
{
    Polynomial result(p);

    auto it_q = find_poly(q);
    auto it_r = find_poly(r);

    Term *t_q = it_q->first;
    
    while (t_q != nullptr)
    {
        Term *t_r = it_r->first;

        while (t_r != nullptr)
        {
            add_term(result, t_q->coef * t_r->coef, t_q->expo + t_r->expo);
            t_r = t_r->next;
        }
        t_q = t_q->next;
    }

    if (result.first == nullptr)
        cout << "error!" << endl;
    else
        insert_polynomial(result);
}

// struct Term
// {
//     int coef;
//     int expo;
//     Term *next = nullptr;

//     // default 생성자
//     Term() {}

//     // 생성자
//     Term(int c, int e) : coef(c), expo(e) {}
//     Term(int c, int e, Term *p) : coef(c), expo(e), next(p) {}
// };

// struct Polynomial
// {
//     char name;
//     Term *first = nullptr;
//     int size = 0;

//     // default 생성자
//     Polynomial() {}
//     // 생성자
//     Polynomial(char name) : name(name) {}
// };

// vector<Polynomial> polys;