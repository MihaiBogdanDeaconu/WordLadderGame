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

public:
    void generateAdjList();
    void printAdjList() const;
    map<T, T> BFS(T startNode);
    bool displayPath(T start, T end);
};