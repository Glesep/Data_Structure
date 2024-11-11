#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cassert>
#include <vector>

/*
range for문 - for문의 대상의 요소에서 각각을 복사하여 값을 들고온다.
vector를 대상으로 삼을 시 iterator가 가리키는 요소들을 복사한다? <- 알아보기

 */
using namespace std;
struct Person
{
    string name, address;
    string phone, email, web;
};

vector<Person> directory;

vector<string> split_line(string &line, char delimiter)
{
    vector<string> tokens;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, delimiter))
        tokens.push_back(str);
    return tokens;
}

string trim(string str)
{
    int s = 0, t = str.length() - 1;
    ;
    while (s < str.length() && isspace(str[s]))
        s++;
    while (t >= 0 && isspace(str[t]))
        t--;
    if (s <= t)
        return str.substr(s, t - s + 1);
    else
        return "";
}

void load_data(string file_name)
{
    string line;
    ifstream infile(file_name);
    while (getline(infile, line))
    {
        vector<string> tokens = split_line(line, '\t');

        assert(tokens.size() >= 4 && tokens.size() <= 5); // tokens.size() == 4인 경우는 마지막 웹 주소가 없는 사람일 경우 delimiter인 탭으로 끝나기 때문에 tokenizing이 되지 않아 개수가 4가 되는 경우

        Person p;
        p.name = tokens.at(0);
        p.address = tokens.at(1);
        p.phone = tokens.at(2);
        p.email = tokens.at(3);
        p.web = tokens.at(4);
        directory.push_back(p);
    }
    infile.close();
}

void print_person(Person &p) // 참조: 어떤 객체의 이름을 하나 더 추가해주는 행위
{
    cout << p.name << ":" << endl;
    cout << " Address: " << p.address << ":" << endl;
    cout << " Phone: " << p.phone << ":" << endl;
    cout << " Email: " << p.email << ":" << endl;
    cout << " Web: " << p.web << ":" << endl;
}

void list_directory()
{
    for (auto &person : directory)
    {
        print_person(person);
    }
}

// find 명령 처리 함수
void search_directory(string &prefix)
{
    for (auto &p : directory)
    {
        if (p.name.compare(0, prefix.size(), prefix) == 0) // 문자열 일부를 비교할 때 compare(start, length, target) 함수를 사용한다.
            print_person(p);
        else if (p.name.compare(0, prefix.size(), prefix) > 0)
            break;
    }
}

void search_directory_AND(vector<string> &tokens)
{
    for (auto &p : directory)
    {
        bool target = true;
        for (int i = 0; i < (int)tokens.size(); i++)
        { // 인덱스 실수 하지말기

            // 찾는 대상이 아닌 경우
            if (p.name.find(tokens[i]) == -1 &&
                p.address.find(tokens[i]) == -1 &&
                p.phone.find(tokens[i]) == -1 &&
                p.email.find(tokens[i]) == -1 &&
                p.web.find(tokens[i]) == -1)
            {
                target = false;
                break;
            }
        }

        if (target)
        {
            print_person(p);
        }
    }
}

Person get_person_info(string name)
{
    Person p;
    string line;
    p.name = name;
    cout << " Address: ";
    getline(cin, line);
    p.address = trim(line);
    cout << " Phone: ";
    getline(cin, line);
    p.phone = trim(line);
    cout << " Email: ";
    getline(cin, line);
    p.email = trim(line);
    cout << " Web: ";
    getline(cin, line);
    p.web = trim(line);
    return p;
}

void add_person(string name)
{
    Person p = get_person_info(name);
    auto it = directory.begin();
    while (it != directory.end() && it->name <= name) // reverse_iterator를 사용하면 뒤에서부터 비교할 수 있다.
        it++;
    it = directory.insert(it, p);
}

void delete_person(string name)
{
    string answer;
    for (auto it = directory.begin(); it != directory.end();)
    {
        if (it->name.compare(0, name.size(), name) == 0)
        {
            cout << "Want to delete '" << it->name << "'? ";
            cin >> answer;
            if (answer == "yes" || answer == "y")
                it = directory.erase(it);
            else
                it++;
        }
        else if (it->name.compare(0, name.size(), name) > 0)
            break;
        else
            it++;
    }
}

void save_directory()
{
    ofstream outfile("address.tsv");
    for (auto &p : directory)
        outfile << p.name << '\t' << p.address << '\t' << p.phone
                << '\t' << p.email << '\t' << p.web << endl;
    outfile.close();
}

int main()
{
    load_data("address.tsv");
    string command, arguments;
    while (1)
    {
        cout << "$ ";
        cin >> command;

        if (command == "exit")
            break;

        if (command == "list")
            list_directory();

        else if (command == "find")
        {
            getline(cin, arguments);
            string name = trim(arguments);
            if (name.length() <= 0)
                continue;
            search_directory(name);
        }

        else if (command == "search")
        {
            getline(cin, arguments); // while문 조건 안에 표준입력스트림을 넣으면 계속 반복됨
            stringstream sstream(arguments);
            vector<string> tokens; // token들을 저장할 벡터 정의

            while (getline(sstream, arguments, '&'))
            {
                tokens.push_back(arguments);
            }

            // tokenizing된 문자열에서 공백 제거
            for (auto it = tokens.begin(); it < tokens.end(); it++)
            {
                *it = trim(*it);
            }

            search_directory_AND(tokens);
        }

        else if (command == "add")
        {
            getline(cin, arguments);
            string name = trim(arguments);
            if (name.length() <= 0)
                continue;
            add_person(name);
        }

        else if (command == "delete")
        {
            getline(cin, arguments);
            string name = trim(arguments);
            if (name.length() <= 0)
                continue;
            delete_person(name);
        }

        else if (command == "save")
        {
            save_directory();
        }
    }
    return 0;
}
