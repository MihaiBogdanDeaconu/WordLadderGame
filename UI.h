#pragma once
#include "graph.h"
#include "PlayerMode.h"


template <typename T>
class UI
{
private:
    Graph<T> dictionary;

public:
    // UI();
    void displayMainMenu() const;
    void run();
    void automaticModeMenu();
    void playingModeMenu();
    void analyticsMenu();
    bool readOption(int &option);
    bool readWord(string &word);
    void toLowerWord(string &word);
};