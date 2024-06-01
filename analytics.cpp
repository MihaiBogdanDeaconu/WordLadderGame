#include "analytics.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


/**
 * @brief Checks if a file is empty
 * 
 */
bool isFileEmpty(std::ifstream& file) {
    return file.peek() == std::ifstream::traits_type::eof();
}


/**
 * @brief Load game data into a CSV file
 * 
 * @param pm The player mode object containing game data
 * @param startWord The starting word of the game
 * @param endWord The target word of the game
 * @param optimalMovesNr The optimal number of moves to reach the target word
 */
void Analytics::loadData(PlayerMode const &pm, string startWord, string endWord, int optimalMovesNr) const
{
    std::ifstream infile("username.csv");
    bool isEmpty = isFileEmpty(infile);
    infile.close();

    std::ofstream file("username.csv", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    if (isEmpty) {
        file << "PlayerName,StartWord,EndWord,NumberOfHints,NumberOptimalMoves,NumberOfMovesUsed,WordsUsed\n";
    }
    file << pm.getName() << ",";
    file << startWord << ",";
    file << endWord << ",";
    file << pm.getNrHints() << ",";
    file << optimalMovesNr << ",";
    file << pm.getNrWordsUsed() << ",";

    vector<string> wordsUsed = pm.getWordsUsed();
    for (size_t i = 0; i < wordsUsed.size(); ++i) {
        file << wordsUsed[i];
        if (i < wordsUsed.size() - 1) {
            file << ";";
        }
    }

    file << "\n";

    file.close();
}


/**
 * @brief Parse a line from a CSV file
 * 
 * @param line The line to parse
 * @return std::vector<std::string> The parsed fields
 */
std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream sstream(line);
    std::string field;

    while (getline(sstream, field, ',')) {
        if (sstream.eof() && !field.empty()) {
            std::stringstream wordStream(field);
            std::string word;
            while (getline(wordStream, word, ';')) {
                result.push_back(word);
            }
        } else {
            result.push_back(field);
        }
    }
    return result;
}


/**
 * @brief Get game data for a specific player
 * 
 * @param playerName The name of the player
 * @return bool True if data is found, False otherwise
 */
bool Analytics::getData(string playerName)
{
    std::ifstream file("username.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return false; // Error code
    }
    std::string line;
    if (getline(file, line)) {
        while (getline(file, line)) {
            std::vector<std::string> fields = parseCSVLine(line);

            if (fields[0] == playerName) {
                ++this->numberOfGames;
                this->numberOfHints += std::stoi(fields[3]);
                this->numberOfMoves += std::stoi(fields[5]);
                for(int i = 6; i < fields.size(); ++i)
                    this->uniqueWords.insert(fields[i]);
            }
        }
    }
    file.close();
    if(this->numberOfGames == 0)
        return false;
    return true;    
}