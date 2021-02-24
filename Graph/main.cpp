#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
    Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 3);
    g.addEdge(2, 5, 4);
    g.addEdge(1, 4, 5);
    g.addEdge(4, 3, 6);
    g.addEdge(5, 3, 7);
    g.addEdge(4, 7, 8);
    g.addEdge(3, 6, 8);
    g.addEdge(3, 7, 9);
    g.addEdge(3, 8, 11);
    g.addEdge(5, 8, 12);
    g.addEdge(8, 6, 13);
    g.addEdge(7, 6, 14);

   cout<<  g.findPathCountBetween(0, 3);


	return 0;
}