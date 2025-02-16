#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <list>
#include "card.h"

using namespace std;

class List {
    private:
    //list<Card> cardList;
    string title;
    string topic;
    string description;
    //could include something for the mastery status of the list - feature I can add later

    public:
    //Default constructor
    List() {
        title = "New List";
        topic = "None";
        description = "None";
    }
    //Overloaded constructor
    List(string t, string o, string d) {
        title = t;
        topic = o;
        description = d;
    }
    void buildList();
    void printList();
    void changeList();
    void saveList();
    List loadList(string filename);
    void flashCards();
    void spelling();
    void quiz();
    void printCards();
    //settahs and gettahs

};

#endif