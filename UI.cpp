#include "UI.h"
#include <iostream>
#include <string>
#include <exception>
#include <chrono>
#include "analytics.h"

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
    cout << "3. Player Analytics\n";
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
                    cout << BLUE_TEXT_COLOR;
                    bool foundPath = this->dictionary.displayPath(startWord, endWord);
                    cout << RESET_TEXT_COLOR;
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
    
    cout << "Number of letters of the words: ";
    cin >> nrLetters;
    
    string startWord = this->dictionary.getRandomWord(nrLetters);
    string endWord;
    vector <string> path;
    while(true)
    {
        endWord = this->dictionary.getRandomWord(nrLetters);
        cout << endWord << endl;
        if(endWord != startWord)
        {
            path = this->dictionary.getPath(startWord, endWord);
            if(path.size() != 1)
                break;
        }
    }

    cout << "Randomly generated, the starting word and the ending words with " <<  nrLetters<< " letters is " << GREEN_TEXT_COLOR << startWord << RESET_TEXT_COLOR << " and " << BLUE_TEXT_COLOR << endWord << RESET_TEXT_COLOR << '.' << endl;
    cout << GREEN_TEXT_COLOR << startWord << RESET_TEXT_COLOR << endl;
    cout << "IF YOU NEED ANY HINT, TYPE \"h\" in the console. If you want to exit, input 0. Now you can start changing this word: \n";
    this->dictionary.displayPath(startWord, endWord);
    
    string prevWord = startWord;
    while(true)
    {
        string curWord;
        cin >> curWord;
        if(curWord == "h")
        {
            pm.incNrHints();
            vector<string> path = this->dictionary.getPath(prevWord, endWord);
            string nextWord = path[1];
            cout << "Hint: ";
            for(int i = 0; i < prevWord.length(); ++i)
            {
                if(prevWord[i] == nextWord[i])
                    cout << prevWord[i];
                else cout << BLUE_TEXT_COLOR << prevWord[i] << RESET_TEXT_COLOR;
            }
            cout << endl;
        }
        else if(curWord == "0")
            break;
        else if(!this->dictionary.validTransformation(prevWord, curWord))
            cout << "This is not a valid transformation! Try again!\n";
        else if(!this->dictionary.existsWord(curWord))
            cout << "This word doesn't exist! Try again!\n";
        else if(curWord == endWord)
        {
            pm.pushWord(curWord);
            cout << "You found the way to the end word!!!\n";
            cout << "Start word: "  << BLUE_TEXT_COLOR << startWord << RESET_TEXT_COLOR << "\nEnd word: " << BLUE_TEXT_COLOR << endWord << RESET_TEXT_COLOR << endl;
            const auto now = chrono::system_clock::now();
            const time_t t_c = chrono::system_clock::to_time_t(now);
            cout << "Date and time of the game: " << BLUE_TEXT_COLOR << ctime(&t_c) << RESET_TEXT_COLOR;
            cout << "You used " << BLUE_TEXT_COLOR << pm.getNrHints() << RESET_TEXT_COLOR << " hints." << endl;
            cout << "You used the words: " << BLUE_TEXT_COLOR;
            pm.displaysWordsUsed();
            cout << RESET_TEXT_COLOR << endl;
            int nrWordsUsed = pm.getNrWordsUsed();
            int optimalNrWordsUsed = this->dictionary.getPath(startWord, endWord).size() - 1;
            if(nrWordsUsed == optimalNrWordsUsed)
                cout << "To reach the end word, you used " << BLUE_TEXT_COLOR << nrWordsUsed << RESET_TEXT_COLOR << " moves, which is in fact the lowest possible." << endl;
            else
                cout << "To reach the end word, you used " << BLUE_TEXT_COLOR << nrWordsUsed << RESET_TEXT_COLOR << " moves, but the most optimal way is " << BLUE_TEXT_COLOR << optimalNrWordsUsed << RESET_TEXT_COLOR << " moves\n";
            
            Analytics al;
            al.loadData(pm, startWord, endWord, optimalNrWordsUsed);
            break;
        }
        else 
        {
            pm.pushWord(curWord);
            cout << "Changed letter: ";
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
void UI<T>::analyticsMenu()
{
    cout << "If you want to come back, input 0!\n";
    bool exit = false;
    string playerName;
    Analytics al;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        cout << "Enter Player Name: ";
        getline(cin, playerName);

        if(playerName == "0")
        {
            exit = true;
            break;
        }  
        if (al.getData(playerName)) {
            break;
        } else {
            cout << "Player Name: " << RED_TEXT_COLOR << playerName << RESET_TEXT_COLOR <<" not found! Please try again!" << endl;
        }
    }

    if(!exit)
    {
        cout << "Player " << GREEN_TEXT_COLOR << playerName << RESET_TEXT_COLOR << " has played " << GREEN_TEXT_COLOR << al.getNumberOfGames() << RESET_TEXT_COLOR << " games,\n";
        cout << "has done " << GREEN_TEXT_COLOR << al.getNumberOfMoves() << RESET_TEXT_COLOR << " moves,\n";
        cout << "has used " << GREEN_TEXT_COLOR << al.getNumberOfHints() << RESET_TEXT_COLOR << " hints,\n";
        cout << "and has used " << GREEN_TEXT_COLOR << al.getUniqueWords().size() << RESET_TEXT_COLOR << " unique words so far, and those are: \n";
        cout << BLUE_TEXT_COLOR;
        for(const auto& word: al.getUniqueWords())
            cout << word << ' ';
        cout << RESET_TEXT_COLOR << endl;
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

            case 3:
                analyticsMenu();
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

        if(option > 3 || option < 0)
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