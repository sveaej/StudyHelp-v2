#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Card {
    //stuff 
    private:
    string term;
    string definition;
    bool isFlagged;

    public:
    //default constructor
    Card() {
        term = "blank";
        definition = "blank";
        isFlagged = false;
    }
    //overloaded constructor
    Card(string t, string d) {
        term = t;
        definition = d;
        isFlagged = false;
    }
    //settahs and gettahs yeahhh
    void setTerm(string);
    string getTerm();
    void setDef(string);
    string getDef();
    void printCard();
    void toggleFlag();
};
#endif
/*
typedef struct Card {
    string term;
    string definiton;
    bool flagged;
} card_t;
*/
//list<card_t> cardList; //The working list of cards being studied


/*
//Functions this program will use
void buildList();

void printList(); //may need an iterator to the first element

void changeList();

void saveList();

void loadList();

void flashCards();

void spelling();

void quiz();

void printMenu();
*/
//Menu function
//Print the list
//Modify the list (which will have add, remove, and reorder)
//Save the list to a file (you will have to name the list something unique)
//Load a list from a file
    //If there's already an active list, will need to clear it (you could just have it delete regardless)
//Flash cards
//Spelling
//Matching?
//Test
//User should be able to view existing saved lists as well! If I can do that
//If you load a list and then change it, how will it save? Probably just overwrite the whole file

