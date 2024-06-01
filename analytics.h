#pragma once
#include "PlayerMode.h"
#include <set>

class Analytics
{
private:
    string playerName;
    set<string> uniqueWords;
    int numberOfMoves = 0;
    int numberOfHints = 0;
    int numberOfGames = 0;

public:
    // Analytics(string pName): playerName(playerName){}
    void loadData(PlayerMode const &pm, string startWord, string endWord, int optimalMovesNr) const;
    bool getData(string playerName);
    const string& getPlayerName() const { return playerName; }
    const set<string>& getUniqueWords() const { return uniqueWords; }
    int getNumberOfMoves() const { return numberOfMoves; }
    int getNumberOfHints() const { return numberOfHints; }
    int getNumberOfGames() const { return numberOfGames; }
};