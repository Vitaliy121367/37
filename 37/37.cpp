#include "MyQueue.h"
#include "Song.h"
#include <Windows.h>
#include <vector>

int main()
{
    /*myQueue::Queue<int>a;
    a.push_back(7);
    a.push_back(4);
    a.push_back(9);
    a.push_back(2);

    while (!a.isEmpty()) {
        cout << "First: " << a.first() << endl;
        a.show();
        a.pop_front();
    }
    a.show();*/
    vector<Song>allMusic;
    ifstream file("music.txt");
    if (file.is_open())
    {
        while (!file.eof()) 
        {
            Song a;
            a.load(file);
            allMusic.push_back(a);
        }
        file.close();
    }
    cout << "Size: " << allMusic.size()<<endl;
    Sleep(3000);
    system("CLS");

    myQueue::Queue<Song> player;
    player.push_back(allMusic[5]);
    player.push_back(allMusic[1]);
    player.push_back(allMusic[5]);
    player.push_back(allMusic[3]);

    while (!player.isEmpty()) {
        player.first().show();
        player.pop_front();
        Sleep(3000);
        system("CLS");
    }
}