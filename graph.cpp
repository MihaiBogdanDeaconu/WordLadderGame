#include "graph.h"
#include <iostream>
#include <fstream> 
#include <vector>
#include <map>
#include <queue>
#include <random>

using namespace std;


/**
* @brief Construct a new Graph object
* 
*/
template <typename T>
Graph<T>::Graph()
{
    generateAdjList();
}


/**
* @brief Generates the adjacency list for the graph based on the dictionary of words
* 
*/
template<typename T>
void Graph<T>::generateAdjList()
{
    ifstream in("dictionary.txt"); 
    multimap<string, string> multimp;   

    string word;
    while(in >> word)
    {
        this->words.push_back(word);
        for(int i = 0 ; i < word.size(); ++i)
        {
            string auxStr = word;
            auxStr[i] = '*';
            multimp.insert(make_pair(auxStr, word));
        }
    }
    
    for (auto it = multimp.begin(); it != multimp.end(); ) {
        auto key = it->first;
        auto range = multimp.equal_range(key);
        
        for (auto inner_it = range.first; inner_it != range.second; ++inner_it) {
            for (auto inner_it2 = range.first; inner_it2 != range.second; ++inner_it2) {
                if (inner_it != inner_it2) {
                    this->adjList.insert(make_pair(inner_it->second, inner_it2->second));
                }
            }
        }
        it = range.second;
    }
}


/**
* @brief Prints the adjacency list of the graph
* 
*/
template<typename T>
void Graph<T>::printAdjList() const
{
    T currentKey;
    bool firstKey = true;

    for(auto const& pair : this->adjList)
    {
        if (pair.first != currentKey) {
            if (!firstKey) {
                cout << endl;  
            } else {
                firstKey = false;
            }
            cout << pair.first << ": ";
            currentKey = pair.first;
        } else {
            cout << ", ";  
        }
        cout << pair.second;
    }
    cout << endl;
}


/**
* @brief Performs Breadth-First Search (BFS) on the graph starting from the given node
* 
* @param startingNode The starting node for BFS
* @return map<T, T> A map containing the parent nodes of each node visited during BFS
*/
template<typename T>
map<T, T> Graph<T>::BFS(T startingNode)
{
    map<T, bool> visited;
    map<T, T> dads;
    queue<T> myQ;
    for(auto pair: adjList)
    {
        if(pair.first.length() == startingNode.length())
        {
            visited.insert(make_pair(pair.first, false));
            dads.insert(make_pair(pair.first, ""));
        }
    }
    
    myQ.push(startingNode);
    visited[startingNode] = true;

    while(!myQ.empty())
    {
        auto range = adjList.equal_range(myQ.front());
        for(auto it = range.first; it != range.second; ++it)
        {
            if(visited[it->second] == false)
            {
                dads[it->second] = myQ.front();
                visited[it->second] = true;
                myQ.push(it->second);
            }
        }
        myQ.pop();
    }
    return dads;
}


/**
* @brief Displays the shortest path from start to end node
* 
* @param start The starting node
* @param end The ending node
* @return true If a path is found
* @return false If no path is found
*/
template <typename T>
bool Graph<T>::displayPath(T start, T end)
{
    map<T, T> dads;
    vector<T> solution;
    dads = BFS(start);
    bool foundPath = true;
    while(end != "")
    {
       solution.insert(solution.begin(), end);
       end = dads[end];
    }

    if(solution.size() == 1)
        foundPath = false;

    if(foundPath)
    {
        for(T elem: solution)
        {
            cout << elem << ' ';
        }
        cout << endl;
    }

    return foundPath;
}


/**
* @brief Gets the shortest path from start to end node
* 
* @param start The starting node
* @param end The ending node
* @return vector<T> The shortest path from start to end node
*/
template <typename T>
vector<T> Graph<T>::getPath(T start, T end)
{
    map<T, T> dads;
    vector<T> solution;
    dads = BFS(start);
    bool foundPath = true;
    while(end != "")
    {
       solution.insert(solution.begin(), end);
       end = dads[end];
    }

    return solution;
}


/**
* @brief Gets a random word from the dictionary with the specified number of letters
* 
* @param nrLetters The number of letters in the word
* @return T A random word from the dictionary
*/
template <typename T>
T Graph<T>::getRandomWord(int nrLetters)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, this->words.size() - 1);
    while(true)
    {
        int randomIndex = dis(gen);
        if(this->words.at(randomIndex).size() == nrLetters && this->adjList.count(this->words.at(randomIndex)) > 0)
        {
            return this->words.at(randomIndex);
            break;
        }
    }
}


/**
* @brief Checks if a word exists in the dictionary
* 
* @param word The word to check
* @return true If the word exists in the dictionary
* @return false If the word does not exist in the dictionary
*/
template <typename T>
bool Graph<T>::existsWord(T word) const
{
    auto it = this->adjList.find(word);
    return it != this->adjList.end();
}


/**
* @brief Checks if a transformation from originalWord to transformedWord is valid
* 
* @param originalWord The original word
* @param transformedWord The transformed word
* @return true If the transformation is valid
* @return false If the transformation is not valid
*/
template <typename T>
bool Graph<T>::validTransformation(T originalWord, T transformedWord) const
{
    int difs = 0;

    if(originalWord.size() != transformedWord.size())
        return false;

    for(int i = 0; i < originalWord.size(); ++i)
    {
        if(originalWord[i] != transformedWord[i])
            ++difs;
        if(difs > 1)
            return false;
    }

    return true;
}


template class Graph<string>;