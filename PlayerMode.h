#pragma once
#include <iostream>
#include <vector>
using namespace std;

class PlayerMode
{
private:
    string playerName;
    int nrHints;
    vector<string> wordsUsed;

public:
    PlayerMode(): playerName("No name"), nrHints(0){}
    inline void setName(string newName) {this->playerName = newName;}
    inline string getName() const {return this->playerName;}
    inline void incNrHints() {this->nrHints++;}
};