#include<iostream>
using namespace std;

struct Song
{
    string name;
    Song *prev;
    Song *next;
};

Song *head = NULL;
Song *tail = NULL;

void addBeginning(string name)
{
    Song *newSong=new Song;
    newSong->name=name;
    newSong->prev=NULL;
    newSong->next=head;

    if(head == NULL)
        head=tail=newSong;
    else
    {
        head->prev=newSong;
        head=newSong;
    }
}

void addEnd(string name)
{
    Song *newSong=new Song;
    newSong->name=name;
    newSong->next=NULL;
    newSong->prev=tail;

    if(tail == NULL)
        head = tail = newSong;
    else
    {
        tail->next = newSong;
        tail = newSong;
    }
}

void insertAfter(string songName, string newName)
{
    Song *temp = head;

    while(temp != NULL && temp->name != songName)
        temp = temp->next;

    if(temp == NULL)
    {
        cout << "Song not found" << endl;
        return;
    }

    Song *newSong = new Song;
    newSong->name = newName;

    newSong->prev = temp;
    newSong->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = newSong;
    else
        tail = newSong;

    temp->next = newSong;
}

void removeFirst()
{
    if(head == NULL)
    {
        cout << "Playlist is empty" << endl;
        return;
    }

    Song *temp = head;
    head = head->next;

    if(head == NULL)
        tail = NULL;
    else
        head->prev = NULL;

    delete temp;
}

void display()
{
    Song *temp = head;

    cout << "Playlist: ";

    while(temp != NULL)
    {
        cout << temp->name << " ";
        temp = temp->next;
    }

    cout << endl;
}

void countSongs()
{
    int count = 0;
    Song *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Number of songs: " << count << endl;
}

int main()
{
    addBeginning("Song1");
    display();

    addEnd("Song2");
    display();

    addEnd("Song3");
    display();

    insertAfter("Song2", "Song4");
    display();

    countSongs();

    removeFirst();
    display();

    countSongs();

    insertAfter("Song10", "Song5");
    display();

    return 0;
}
