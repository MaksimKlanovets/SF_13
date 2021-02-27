#include "graph.h"
#include "person.h"
#include <iostream>
using namespace std;
#include <string>

int main()
{
  

    Person *names = new Person[9];
    names[0] = Person("Ivan0");
    names[1] = Person("Masha1");
    names[2] = Person("Sonya2");
    names[3] = Person("Maks3");
    names[4] = Person("Andrey4");
    names[5] = Person("Olya5");
    names[6] = Person("Sasha6");
    names[7] = Person("Tolya7");
    names[8] = Person("Igor8");
    

    Graph g;
    g.addVertex(names[0]);
    g.addVertex(names[1]);
    g.addVertex(names[2]);
    g.addVertex(names[3]);
    g.addVertex(names[4]);
    g.addVertex(names[5]);
    g.addVertex(names[6]);
    g.addVertex(names[7]);
    g.addVertex(names[8]);

    g.addEdge(names[0], names[1], 1);
    g.addEdge(names[0], names[2], 2);
    g.addEdge(names[0], names[3], 3);
    g.addEdge(names[2], names[5], 4);
    g.addEdge(names[1], names[4], 5);
    g.addEdge(names[4], names[3], 6);
    g.addEdge(names[5],  names[3], 7);
    g.addEdge(names[4], names[7], 8);
    g.addEdge(names[3], names[6], 8);
    g.addEdge(names[3], names[7], 9);
    g.addEdge(names[3], names[8], 11);
    g.addEdge(names[5], names[8], 12);
    g.addEdge(names[8], names[6], 13);
    g.addEdge(names[7], names[6], 14);

   cout << "All ways-> \t" << g.findPathCount(names[0].getId(), names[3].getId()) << endl;

   cout << "not more than three point-> \t" << g.findPathCountBetween(names[0].getId(), names[3].getId()) << endl;

   const int point = 2;
   cout << "not more than " << point << " point-> \t" << g.findPathCountBetween(names[0].getId(), names[3].getId(),point) << endl;
   
   g.depth(0);

   cout << "Shortest path->  "<<  g.findMinWayDFS(1, 5) << endl;

   g.delVertex(1);
   g.delEdge(0, 1);
   g.delEdge(1, 4);
   g.depth(0);

	return 0;
}