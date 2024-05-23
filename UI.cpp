#include "UI.h"
#include <iostream>
#include <string>
#include <exception>

// ANSI COLORS

#define GREEN_TEXT_COLOR "\e[0;32m"
#define BLUE_TEXT_COLOR "\e[0;34m"
#define RED_TEXT_COLOR "\e[0;31m"
#define RESET_TEXT_COLOR "\x1b[0m"

using namespace std;

// template <typename T>
// UI<T>::UI()
// {
//     this->dictionary.generateAdjList();
// }

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
                    bool foundPath = this->dictionary.displayPath(startWord, endWord);
                    if(!foundPath)
                        cout << "There is no solution for the words you provided! Check the validity of your words!\n";
                    break;
                }
                    
            }
        }
        break;
    }
}

template <typename T>
void UI<T>::playingModeMenu()
{
    PlayerMode pm;
    string playerName;
    int nrLetters;
    cout << "Please input your name and then press ENTER!\n";
    cout << "Player Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, playerName);
    pm.setName(playerName);
    
    cout << "Number of letter of the words: ";
    cin >> nrLetters;
    
    string startWord = this->dictionary.getRandomWord(nrLetters);
    string endWord;
    vector <string> path;
    while(true)
    {
        endWord = this->dictionary.getRandomWord(nrLetters);
        if(endWord != startWord)
        {
            path = this->dictionary.getPath(startWord, endWord);
            if(path.size() != 1)
                break;
        }
    }

    cout << "Randomly generated, the starting word and the ending words with " <<  nrLetters<< " letters is " << GREEN_TEXT_COLOR << startWord << RESET_TEXT_COLOR << " and " << BLUE_TEXT_COLOR << endWord << RESET_TEXT_COLOR << '.' << endl;
    cout << GREEN_TEXT_COLOR << startWord << RESET_TEXT_COLOR << endl;
    cout << "IF YOU NEED ANY HINT, TYPE \"h\" in the console. Now you can start changing this word: \n";
    
    string prevWord = startWord;
    while(true)
    {
        string curWord;
        cin >> curWord;
        if(curWord == 'h')
        {
            pm.incNrHints();
            
        }
        else if(!this->dictionary.validTransformation(prevWord, curWord))
            cout << "This is not a valid transformation! Try again!\n";
        else if(!this->dictionary.existsWord(curWord))
            cout << "This word doesn't exist! Try again!\n";
        else if(curWord == endWord)
        {
            cout << BLUE_TEXT_COLOR << endWord << RESET_TEXT_COLOR << endl;
            cout << "You found the way to the end word!\n";
            break;
        }
        else 
        {
            for(int i = 0; i < prevWord.size(); ++i)
            {
                if(prevWord[i] != curWord[i])
                    cout << RED_TEXT_COLOR << curWord[i] << RESET_TEXT_COLOR;
                else cout << curWord[i];
            }
            cout << endl;
            prevWord = curWord;
        }
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
                playingModeMenu();
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

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Invalid input! Please enter an integer.");
        }

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