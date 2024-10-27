#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <cassert>
#include <windows.h>
using namespace std;


int id_counter = 0; // 각 Song 객체마다 서로 다른 index를 부여하기 위해서 하나의 전역변수를 사용한다.
struct Song;        // Song의 전방 선언, Artist 이후에 나올것이라고 컴파일러에게 알려줌

struct Artist
{
    string name;
    list<Song *> songs;
    Artist() {}
    Artist(string name) : name(name) {}
};

struct Song
{
    int index;
    string title, album, mv_url;
    Artist *artist;
    Song() {}
    Song(string ti, Artist *art, string alb, string mv) : title(ti), artist(art), album(alb), mv_url(mv)
    {
        index = id_counter++; // 생성된 모든 Song 객체에서 유일한 index를 부여한다.
    }
};

list<Artist *> artist_directory[256]; // 이름의 첫 문자를 배열 인덱스로 사용한다.

const int SONG_DIRECTORY_SIZE = 10;
list<Song *> song_directory[SONG_DIRECTORY_SIZE];

const string datafilename = "songs.csv";

vector<string> split_line(string &line, char delimiter)
{
    vector<string> tokens;
    stringstream sstream(line);
    string str;
    while (getline(sstream, str, delimiter))
    {
        tokens.push_back(str);
    }
    return tokens;
}

Artist *find_artist(string name)
{
    list<Artist *> artist_list = artist_directory[(unsigned char)name[0]];
    for (auto it = artist_list.begin(); it != artist_list.end(); it++)
    {
        if ((*it)->name == name)
            return *it;
    }
    return nullptr;
}

// keyword로 시작하는 가수를 찾는 함수
// 반환값은 키워드를 접두사로 갖는 가수를 가리키는 이터레이터
vector<Artist *> find_artists(string keyword)
{
    vector<Artist *> artists_vec;

    list<Artist *> artist_list = artist_directory[(unsigned char)keyword[0]];
    for (auto it = artist_list.begin(); it != artist_list.end(); it++)
    {
        if ((*it)->name.compare(0, keyword.length(), keyword) == 0) // 앞에 부분만 확인하는 조건문 작성
            artists_vec.push_back(*it);
    }
    return artists_vec;
}

void print_artist(Artist *p)
{
    cout << p->name << ":" << endl;
    for (auto s : p->songs)
    {
        cout << " " << s->index << ":" << s->title << ", " << s->album << ", " << s->mv_url << endl;
    }
}

void print_artist_keyword(vector<Artist *> artist_vec)
{

    if (artist_vec.size() == 0)
    {
        cout << "Artist not found" << endl;
        return;
    }

    for (auto it = artist_vec.begin(); it != artist_vec.end(); it++)
    {
        print_artist(*it);
    }
}
void print_artist_directory()
{
    for (int i = 0; i < 256; i++)
    {
        list<Artist *> &artist_list = artist_directory[i];
        for (auto ptr : artist_list)
        {
            print_artist(ptr);
        }
    }
}

// 제목에 키워드가 포함되었으면 출력
void print_song_directory_withKeyword(string keyword)
{
    for (int i = 0; i < SONG_DIRECTORY_SIZE; i++)
    {
        list<Song *> &song_list = song_directory[i];
        for (auto s : song_list)
        {
            if (s->title.find(keyword) != string::npos)
            {
                cout << s->index << ":" << s->title << ", "
                     << s->artist->name << ", " << s->album << ", " << s->mv_url << endl;
            }
        }
    }
}

void print_song_directory()
{
    for (int i = 0; i < SONG_DIRECTORY_SIZE; i++)
    {
        list<Song *> &song_list = song_directory[i];
        for (auto s : song_list)
        {
            cout << " " << s->index << ":" << s->title << ", "
                 << s->artist->name << ", " << s->album << ", " << s->mv_url << endl;
        }
    }
}

Artist *add_artist(string name)
{
    Artist *ptr_artist = new Artist(name);
    list<Artist *> &artist_list = artist_directory[(unsigned char)name[0]];
    artist_list.push_back(ptr_artist);
    return ptr_artist;
}

void add_song(string title, string artist, string album = "", string mv_url = "")
{
    Artist *artist_ptr = find_artist(artist);
    if (artist_ptr == nullptr)
    {
        artist_ptr = add_artist(artist);
    }
    Song *song_ptr = new Song(title, artist_ptr, album, mv_url);
    artist_ptr->songs.push_back(song_ptr);
    list<Song *> &song_list = song_directory[song_ptr->index % SONG_DIRECTORY_SIZE];
    song_list.push_back(song_ptr);
}

void load_songs(string filename)
{
    string line;
    ifstream songfile(filename);
    while (getline(songfile, line))
    {
        vector<string> tokens = split_line(line, ',');
        assert(tokens.size() == 4 || tokens.size() == 3);
        if (tokens.size() == 4)
            add_song(tokens[0], tokens[1], tokens[2], tokens[3]);
        else
            add_song(tokens[0], tokens[1], tokens[2]);
    }
    songfile.close();
}

list<Song *>::iterator remove_song(int song_index) {
    list<Song *> &song_list = song_directory[song_index % 10];
    Artist *artist_forSong;
    for (auto it = song_list.begin(); it != song_list.end(); it++) {
        if ((*it)->index == song_index) {
            artist_forSong = (*it)->artist; // 아티스트 객체 내에서도 삭제위해 아티스트 포인터를 미리 받음
            song_list.erase(it);      // 삭제되었으므로 iterator는 한칸 뒤로 움직임, it++할 필요 X 
            break;                    // 대상 삭제됨, 반복 종료
        }
    }

    for (auto it = artist_forSong->songs.begin(); it != artist_forSong->songs.end(); it++) {
        if ((*it)->index == song_index) {
            delete (*it);       // 할당 해제
            it = artist_forSong->songs.erase(it);    // 리스트 내에서 삭제
            return it;      // remove_artist를 위한 iterator 전송
        }

        return it;
    }
}

/*
https://infjin.tistory.com/143 : cin >> 과 getline을 혼용할 때 사용법
*/
void remove_artist(string keyword)
{
    list<Artist *> &artist_list = artist_directory[(unsigned char)keyword[0]];

    for (auto it = artist_list.begin(); it != artist_list.end(); )
    {
        if ((*it)->name.compare(0, keyword.length(), keyword) == 0)
        { // 앞에 부분만 확인하는 조건문 작성
            string YesOrNo;
            cout << "Want to remove artist '" << (*it)->name << "' ? ";
            cin >> YesOrNo;
            if (YesOrNo == "yes")
            {
                // artist 내부 노래 삭제
                list<Song *> &song_list_forArtist = (*it)->songs;
                for (auto it2 = song_list_forArtist.begin(); it2 != song_list_forArtist.end();) {
                    // remove_song에서 iterator를 삭제했기 때문에 it2가 작동하지 않는 문제 발생
                    // 이는 remove_song에서 삭제된 그 다음 이터레이터를 반환하는 형식으로 해결
                    it2 = remove_song((*it2)->index);
                }

                it = artist_list.erase(it); // 삭제되었으므로 iterator는 한칸 뒤로 움직임, it++할 필요 X
                cin.ignore();               // cin >> 이후 getline을 했다면 버퍼에 '\n'이 남아있으므로 '\n'을 지워주는 작업 요함
                continue;
            }
        }
        it++;
    }
}

int main()
{
    load_songs(datafilename);

    while (true)
    {
        cout << "$ ";
        string command;
        getline(cin, command);
        // command 토큰으로 나누기
        vector<string> command_token = split_line(command, ' ');
        // cout << command_token[0] << " " << command_token[1] << " " <<  command_token[2] << endl;

        if (command_token[0] == "list")
        {
            if (command_token.size() == 1)
                print_song_directory();
            else if (command_token[1] == "-a")
                print_artist_directory();
        }

        else if (command_token[0] == "add")
        {
            string title, artist, album, mvUrl;

            cout << " Title: ";
            getline(cin, title);

            cout << " Artist: ";
            getline(cin, artist);

            cout << " Album: ";
            getline(cin, album);

            cout << " MV url: ";
            getline(cin, mvUrl);

            add_song(title, artist, album, mvUrl);
        }

        else if (command_token[0] == "find")
        {

            if (command_token[1] == "-a")
            {
                vector<Artist *> artist_vec = find_artists(command_token[2]);
                print_artist_keyword(artist_vec);
            }
            else
            {
                // 제목이 키워드를 포함하는 모든 노래 찾기
                print_song_directory_withKeyword(command_token[1]);
            }
        }

        else if (command_token[0] == "remove")
        {
            if (command_token[1] == "-a")
            {
                remove_artist(command_token[2]);
            }
            
            else {
                int song_index = stoi(command_token[1]);
                remove_song(song_index);
            }
        }

        else if (command_token[0] == "exit")
            break;
    }
    return 0;
}