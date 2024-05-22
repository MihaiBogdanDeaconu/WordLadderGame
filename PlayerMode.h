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
    inline void setName(string newName) {this->playerName = newName;}
    inline string getName() const {return this->playerName;}
};