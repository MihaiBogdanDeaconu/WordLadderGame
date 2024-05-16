#include "graph.h"
#include <iostream>

using namespace std;

int main()
{
    Graph<string> gf;
    gf.generateAdjList();
    gf.printAdjList();
    
    return 0;
}