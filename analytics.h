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
    /**
     * @brief Load game data into a CSV file
     * 
     * @param pm The player mode object containing game data
     * @param startWord The starting word of the game
     * @param endWord The target word of the game
     * @param optimalMovesNr The optimal number of moves to reach the target word
     */
    void loadData(PlayerMode const &pm, string startWord, string endWord, int optimalMovesNr) const;
    

    /**
     * @brief Get game data for a specific player
     * 
     * @param playerName The name of the player
     * @return bool True if data is found, False otherwise
     */
    bool getData(string playerName);
    
    
    /**
     * @brief Get the player's name
     * 
     * @return const string& The player name
     */
    const string& getPlayerName() const { return playerName; }
    
    
    /**
     * @brief Get the set of unique words used by the player
     * 
     * @return const set<string>& The set of unique words
     */
    const set<string>& getUniqueWords() const { return uniqueWords; }
    
    
    /**
     * @brief Get the total number of moves made by the player
     * 
     * @return int The number of moves
     */
    int getNumberOfMoves() const { return numberOfMoves; }
    
    
    /**
     * @brief Get the total number of hints used by the player
     * 
     * @return int The number of hints
     */
    int getNumberOfHints() const { return numberOfHints; }
    
    
    /**
     * @brief Get the total number of games played by the player
     * 
     * @return int The number of games
     */
    int getNumberOfGames() const { return numberOfGames; }
};