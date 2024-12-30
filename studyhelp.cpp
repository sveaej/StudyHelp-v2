#include "card.h"
#include "list.h"
#include "card.cpp"
#include "list.cpp"
#include <iostream>

//This function prints the initial menu
int printListMenu() {
    int choice = 0;
    cout << "** Welcome to Svizlet!! The tool for all of your studying needs. **" << endl;
    cout << "\nPlease select an option to get started." << endl;
    cout << "1. Create a new study set\n2. Load an existing study set\n3. Quit" << endl;
    cout << "\nType in the number corresponding to your choice." << endl;
    cin >> choice;
    return choice;
}

//This function prints the main menu
int printMainMenu() {
    int choice = 0;
    //Menu options:
    //return to initial menu to get a different list, edit the existing list
    cout << "Now that you have a list, please choose an activity!" << endl;
    cout << "\nPlease select an option to get started." << endl;
    cout << "1. Flash cards\n2. Spelling practice\n3. Test\n4. Print list\n5. Edit list\n6. Use a different list\n7. Quit" << endl;
    cout << "\nType in the number corresponding to your choice." << endl;
    return choice;
}

bool saveListMenu(List &currentList) {
    char choice;
    bool isSaved = false;
    //Ask whether the user wants to save the list
    //Repeat until user enters a valid option
    bool stop = true;
    do {
        cout << "\nSave this list? y/n" << endl;
        cin >> choice;
        switch(choice) {
            case 'y':
                currentList.saveList(); //writes the current list to a file
                //could have this return a bool later so we know whether it was successful
                isSaved = true;
                stop = true;
                break;
            case 'n':
                cout << "\nVery well. This list will not be saved." << endl;
                break;
            default:
                cout << "\nI don't understand that option." << endl;
                stop = false;
                break;
        }
    } while(!stop);

    return isSaved;
}
//This function contains the workflow for creating a new list.
//Returns true if successful and false if unsuccessful.
bool createNewList(List &newList) {
    //Default initialize the new list
    newList = List();
    bool isCreated;
    //Print the empty list info to show the user
    cout << endl;
    newList.printList();
    //Get info for the list... or not
    char choice;
    do {
        cout << "\nAdd info to this list? y/n" << endl;
        cin >> choice;
        switch(choice) {
            case 'y':
                newList.buildList();
                break;
            case 'n':
                cout << "Very well." << endl;
                break;
            default:
                cout << "I don't understand that option." << endl;
                break;
        }
    } while(choice != 'y' && choice != 'n');

    //Save list
    isCreated = saveListMenu(newList);
    //Returns true if a new list is saved and false if it is not
    return isCreated;
}

//This function 
bool loadListFromFile(List &newList) {
    //stuff happens here
    return false;
}

//This function gets the current working list by either having the user create one 
//or loading one from a file.
List getCurrentList() {
    int listChoice = 0;
    bool stop = false;
    List currentList;
    string filename;
    while (!stop) {
        //Print the list menu
        listChoice = printListMenu();
        //initialize current list object with choices from the menu
        switch(listChoice) {
            case 1:
                stop = createNewList(currentList);
                if (!stop) {
                    cout << "The list was not created. Returning to initial menu." << endl;
                }
                break;
            case 2:
                //Choose a file to load the list from
                cout << "Please select a file to load the list from." << endl;
                //Show a list of the available files
                //build list of available files function here?
                //list files function here?
                //for now, I'll just have the user enter the filename
                cout << "For now, just enter the filename." << endl;
                cin >> filename;
                //Create a default list? 
                currentList = currentList.loadList(filename); //this should take in a filename or maybe a file stream object?
                //would it be good to do the file i/o in here or would it be good to do it in the class?
                stop = true;
                break;
            case 3:
                cout << "Thank you for using Svizlet!" << endl;
                stop = true;
                break;
            default:
                cout << "I don't understand that option." << endl;
                stop = false;
                break;
        }
    }
    return currentList;
}

int main(int argc, char* argv[]) {
    bool stop = false;
    int choice = 0;
    int listChoice = 0;
    List currentList;
    List * listPtr;
    string filename;
    //Print the list menu
    currentList = getCurrentList();
    listPtr = &currentList;
    //make sure the list isn't empty
    if (listPtr == nullptr) {
        return 1;
    }
    //After the list is initialized, we print the menu for the main list operations
    choice = printMainMenu();

    do {
        stop = false;
        switch(choice) {
            case 1: currentList.flashCards();
                break;
            case 2: currentList.spelling();
                break;
            case 3: currentList.quiz();
                break;
            case 4: currentList.printList();
                break;
            case 5:
                //Edit list
                currentList.changeList();
                //ask to save changes
                //bool saved = false;
                //saved = saveListMenu(currentList);
                //if (!saved) {
                    //cout << "Failed to save changes." << endl;
                //}
                break;
            case 6:
                //Use a different list
                currentList = getCurrentList();
                //Warning: this list could be empty!
                //Gonna change this later so that this action can be undone
                break;
            case 7:
                //quit
                stop = true;
                break;
            default:
                cout << "I don't understand that option." << endl;
                break;
        }
    } while (!stop);

    return 0;
}