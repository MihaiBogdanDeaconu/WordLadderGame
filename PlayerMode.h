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
    inline int getNrHints() const {return this->nrHints;}
    inline void pushWord(string word) {this->wordsUsed.push_back(word);}
    inline void displaysWordsUsed() const
    {
        for(const auto &word: this->wordsUsed)
            cout << word << ' ';
    }
    inline vector<string> getWordsUsed() const {return this->wordsUsed;}
    inline int getNrWordsUsed() const {return this->wordsUsed.size();}
};