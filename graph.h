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
    Graph<T>();
    void generateAdjList();
    void printAdjList() const;
    map<T, T> BFS(T startNode);
    bool displayPath(T start, T end);
    T getRandomWord(int nrLetters);
    bool existsWord(T word) const;
    bool validTransformation(T originalWord, T transformedWord) const;
    vector<T> getPath(T start, T end);
};