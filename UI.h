#pragma once
#include "graph.h"
#include "PlayerMode.h"


template <typename T>
class UI
{
private:
    Graph<T> dictionary;

public:
    /**
     * @brief Display the main menu options
     * 
     */
    void displayMainMenu() const;


    /**
     * @brief Run the user interface
     * 
     */
    void run();


    /**
     * @brief Handle automatic mode menu
     * 
     */
    void automaticModeMenu();


    /**
     * @brief Handle playing mode menu
     * 
     */
    void playingModeMenu();


    /**
     * @brief Handle player analytics menu
     * 
     */
    void analyticsMenu();


    /**
     * @brief Read an integer option from input
     * 
     * @param option The option selected by the user
     * @return true If the option is read successfully
     * @return false If an error occurs while reading the option
     */
    bool readOption(int &option);


    /**
     * @brief Read a word from input
     * 
     * @param word The word entered by the user
     * @return true If the word is read successfully
     * @return false If an error occurs while reading the word
     */
    bool readWord(string &word);


    /**
     * @brief Convert a word to lowercase
     * 
     * @param word The word to convert to lowercase
     */
    void toLowerWord(string &word);
};