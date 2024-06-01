#pragma once
#include <vector>
#include <map>
#include <iostream>
using namespace std;

template <typename T>
class Graph
{
private:
    multimap<T, T> adjList;
    vector<T> words;

public:
    /**
     * @brief Construct a new Graph object
     * 
     */
    Graph<T>();


    /**
     * @brief Generates the adjacency list for the graph based on the dictionary of words
     * 
     */
    void generateAdjList();


    /**
     * @brief Prints the adjacency list of the graph
     * 
     */
    void printAdjList() const;


    /**
     * @brief Performs Breadth-First Search (BFS) on the graph starting from the given node
     * 
     * @param startingNode The starting node for BFS
     * @return map<T, T> A map containing the parent nodes of each node visited during BFS
     */
    map<T, T> BFS(T startNode);


    /**
     * @brief Displays the shortest path from start to end node
     * 
     * @param start The starting node
     * @param end The ending node
     * @return true If a path is found
     * @return false If no path is found
     */
    bool displayPath(T start, T end);


    /**
     * @brief Gets a random word from the dictionary with the specified number of letters
     * 
     * @param nrLetters The number of letters in the word
     * @return T A random word from the dictionary
     */
    T getRandomWord(int nrLetters);


    /**
     * @brief Checks if a word exists in the dictionary
     * 
     * @param word The word to check
     * @return true If the word exists in the dictionary
     * @return false If the word does not exist in the dictionary
     */
    bool existsWord(T word) const;


    /**
     * @brief Checks if a transformation from originalWord to transformedWord is valid
     * 
     * @param originalWord The original word
     * @param transformedWord The transformed word
     * @return true If the transformation is valid
     * @return false If the transformation is not valid
     */

    bool validTransformation(T originalWord, T transformedWord) const;
    
    
    /**
     * @brief Gets the shortest path from start to end node
     * 
     * @param start The starting node
     * @param end The ending node
     * @return vector<T> The shortest path from start to end node
     */
    vector<T> getPath(T start, T end);
};