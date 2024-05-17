#pragma once
#include "graph.h"


template <typename T>
class UI
{
private:
    Graph<T> dictionary;

public:
    UI();
    void displayMainMenu() const;
    void run();
    void automaticModeMenu();
    bool readOption(int &option);
    bool readWord(string &word);
    void toLowerWord(string &word);
};