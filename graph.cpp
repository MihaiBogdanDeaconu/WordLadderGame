#include "graph.h"
#include <iostream>
#include <fstream> 
#include <vector>
#include <map>

using namespace std;
//a
template<typename T>
void Graph<T>::generateAdjList()
{
    ifstream in("dictionary.txt"); 
    multimap<string, string> multimp;   

    string word;
    while(in >> word)
    {
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

template class Graph<string>;