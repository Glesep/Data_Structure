#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Term
{
    int coef;
    int expo;
    Term *next = nullptr;

    Term() {} // default 생성자

    Term(int c, int e) : coef(c), expo(e) {}
    Term(int c, int e, Term *p) : coef(c), expo(e), next(p) {}
};

struct Polynomial
{
    char name;
    Term *first = nullptr;
    int size = 0;

    Polynomial() {}
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
        else if (command == "exit")
            break;
    }
}

void add_term(Polynomial &poly, int c, int e)
{
    if (c == 0)
        return;

    Term *p = poly.first, *q = nullptr;
    while (p != nullptr && p->expo > e)
    {
        q = p;
        p = p->next;
    }

    if (p != nullptr && p->expo == e)
    {
        p->coef += c;
        if (p->coef == 0)
        {
            if (q == nullptr)
                poly.first = p->next;
            else
                q->next = p->next;

            poly.size--;
            delete p;
        }

        return;
    }

    if (q == nullptr)
        poly.first = new Term(c, e, poly.first);
    else
        q->next = new Term(c, e, p);

    poly.size++;
}

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
    cout << pTerm->coef << "x^" << pTerm->expo;
}

void print_poly(Polynomial &p)
{
    cout << p.name << " = ";
    Term *t = p.first;
    while (t != nullptr)
    {
        print_term(t);
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

int calc_term(Term *term, int x) {
    int result = term->coef;
    for (int i = 0; i < term->expo; i++) {
        result *= x;
    }
    return result;
}


int calc_poly(Polynomial poly, int x) {
    int result = 0;
    Term *t = poly.first;
    while(t != nullptr) {
        result += calc_term(t, x);
        t = t->next;
    }

    return result;
}
void handle_calc(char name, int x) {
    auto it = find_poly(name);
    if (it == polys.end())
        cout << "No such polynomial exists." << endl;
    else
        cout << calc_poly(*it, x) << endl;
}

void insert_polynomial(Polynomial p) {
    auto it = find_poly(p.name);

    if (it == polys.end()) {
        polys.push_back(p);
    }

    else {
        clear_poly(*it);
        *it = p;
    }
}

void handle_add(char name, int c, int e) {
    auto it = find_poly(name);
    if (it == polys.end()) {
        cout << "No such polynomial exists." << endl;
        return;
    }

    add_term(*it, c, e);
}

void clear_poly(Polynomial &p) {
    Term *t = p.first, *tmp;

    while(t != nullptr) {
        tmp = t;
        t = t->next;
        delete tmp;
    }
    p.first = nullptr;
}