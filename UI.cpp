#include "UI.h"
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
UI<T>::UI()
{
    this->dictionary.generateAdjList();
}

template <typename T>
void UI<T>::displayMainMenu() const
{
    cout << "1. Automatic Mode\n";
    cout << "2. Playing Mode\n";
    cout << "0. Exit\n";
}

template <typename T>
void UI<T>::automaticModeMenu()
{
    string startWord, endWord;
    while(true)
    {
        cout << "Starting word: ";
        if(readWord(startWord))
        {
            while(true)
            {
                cout << "End word: ";
                if(readWord(endWord))
                {
                    toLowerWord(startWord);
                    toLowerWord(endWord);
                    this->dictionary.displayPath(startWord, endWord);
                    break;
                }
                    
            }
        }
        break;
    }
}

template <typename T>
void UI<T>::run() 
{
    bool running = true;
    while(running)
    {
        displayMainMenu();
        int option;
        cout << "Option: ";
        if(readOption(option))
        {
            switch (option)
            {
            case 1:
                automaticModeMenu();
                break;
            
            case 2:
                //playingModeMenu();
                break;

            case 0:
                running = false;

            default:
                break;
            };
        }
    }
}

template <typename T>
bool UI<T>::readOption(int &option)
{
    try
    {
        cin >> option;
        if(option > 2 || option < 0)
            throw invalid_argument("Invalid Option! Try Again!");
        return true;
    }
    catch(const exception& ex)
    {
        cerr << ex.what() << endl;
        return false;
    }
        
}

template <typename T>
bool UI<T>::readWord(string &word)
{
    try
    {
        cin >> word;
        return true;
    }
    catch(const exception& ex)
    {
        cerr << "The word should be a string!" << endl;
        return false;
    }
        
}

template <typename T>
void UI<T>::toLowerWord(string &word)
{
    for(auto it = word.begin(); it != word.end(); ++it)
        *it = tolower(*it);
}

template class UI<string>;