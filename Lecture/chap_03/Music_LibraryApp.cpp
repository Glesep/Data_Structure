#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <cassert>

using namespace std;


int id_counter = 0; // 각 Song 객체마다 서로 다른 index를 부여하기 위해서 하나의 전역변수를 사용한다.
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

struct Artist
{
    string name;
    list<Song *> songs;
    Artist() {}
    Artist(string name) : name(name) {}
};

list<Artist *> artist_directory[256]; // 이름의 첫 문자를 배열 인덱스로 사용한다.
const int SONG_DIRECTORY_SIZE = 10;
list<Song *> song_directory[SONG_DIRECTORY_SIZE];
const string datafilename = "melon50.csv";
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
void print_artist(Artist *p)
{
    cout << p->name << ":" << endl;
    for (auto s : p->songs)
    {
        cout << " " << s->index << ":" << s->title << ", " << s->album << ", " << s->mv_url << endl;
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

void print_song_directory()
{
    for (int i = 0; i < SONG_DIRECTORY_SIZE; i++)
    {
        list<Song *> &song_list = song_directory[i];
        for (auto s : song_list)
        {
            cout << " " << s->index << ":" << s->title << ", "
                 << s->artist->name <<
                ", " << s->album << ", " << s->mv_url << endl;
        }
    }
}
int main()
{
    load_songs(datafilename);
    print_artist_directory();
    print_song_directory();
    return 0;
}