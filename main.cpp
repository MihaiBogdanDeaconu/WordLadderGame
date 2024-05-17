#include "graph.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    Graph<string> gf;
    gf.generateAdjList();
    //gf.printAdjList();
    // gf.displayPath("LAME", "SOME");
    map<string, string> dads;
    // dads = gf.BFS("LAME");
    // for(auto pair: dads)
    // {
    //     cout << pair.first << ' ' << pair.second << endl;
    // }
    gf.displayPath("LAME", "SASS");
    return 0;
}