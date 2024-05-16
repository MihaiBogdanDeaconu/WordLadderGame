#pragma once
#include <vector>
#include <map>
#include <iostream>
using namespace std;

template <typename t>
class Graph
{
private:
    multimap<t, t> adjList;

public:
    void generateAdjList();
    void printAdjList() const;
};