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
    /**
     * @brief Construct a new Player Mode object
     * 
     */
    PlayerMode(): playerName("No name"), nrHints(0){}
    
    
    /**
     * @brief Set the name of the player
     * 
     * @param newName The new name of the player
     */
    inline void setName(string newName) {this->playerName = newName;}
    
    
    /**
     * @brief Get the name of the player
     * 
     * @return string The name of the player
     */
    inline string getName() const {return this->playerName;}
    
    
    /**
     * @brief Increment the number of hints used by the player
     * 
     */
    inline void incNrHints() {this->nrHints++;}
    
    
    /**
     * @brief Get the number of hints used by the player
     * 
     * @return int The number of hints used
     */
    inline int getNrHints() const {return this->nrHints;}
    
    
    /**
     * @brief Add a word to the list of words used by the player
     * 
     * @param word The word to be added
     */
    inline void pushWord(string word) {this->wordsUsed.push_back(word);}
    
    
    /**
     * @brief Display the words used by the player
     * 
     */
    inline void displaysWordsUsed() const
    {
        for(const auto &word: this->wordsUsed)
            cout << word << ' ';
    }
    
    
    /**
     * @brief Get the words used by the player
     * 
     * @return vector<string> The words used by the player
     */
    inline vector<string> getWordsUsed() const {return this->wordsUsed;}
    
    
    /**
     * @brief Get the number of words used by the player
     * 
     * @return int The number of words used by the player
     */
    inline int getNrWordsUsed() const {return this->wordsUsed.size();}
};