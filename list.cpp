#include "list.h"
//gonna need to include the stuff for the file io

//This function builds a list from scratch
void List::buildList() {
    //The building the list workflow will go here
    //Name the list, I guess that should also be optional
    //Add a description, optional
    //add a topic, optional
    //Start adding terms
}

//This function prints the contents of a list.
void List::printList() {
    cout << "List Title: " << title << endl;
    cout << "List Topic: " << topic << endl;
    cout << "Description: " << description << endl;
    printCards();
}

//This function edits an existing list. Remember, I'm working with linked lists here. May need an iterator.
void List::changeList() {
    //stuff
}

//This function writes the list to a file and names the file after the list
void List::saveList() {
    //assumed to be the current list? 
}

//Loads a list from a saved file into the class
List List::loadList(string filename) {
    //stuff
    return *this; //return the current list object. Hopefully this will work
}

void List::flashCards() {
    //stuff
}

void List::spelling() {
    //stuff 
}

void List::quiz() {
    //stuff
}

void List::printCards() {
    //if no cards, print "No Cards"
    cout << "No Cards" << endl;
}