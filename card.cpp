#include "card.h"

void Card::setTerm(string t) {
    term = t;
}

string Card::getTerm() {
    return term;
}

void Card::setDef(string d) {
    definition = d;
}

string Card::getDef() {
    return definition;
}

void Card::toggleFlag() {
    if (isFlagged) {
        isFlagged = false;
    }
    else {
        isFlagged = true;
    }
}

void Card::printCard() {
    cout << term << endl;
    cout << definition << endl;
    if (isFlagged) {
        cout << "This term is flagged.\n";
    }
    else {
        cout << "This term is not flagged.\n";
    }
}