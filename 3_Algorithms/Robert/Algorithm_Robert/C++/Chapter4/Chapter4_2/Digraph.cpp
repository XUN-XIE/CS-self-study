#include "Digraph.hpp"

int main()
{
    Digraph DG("tinyDG.txt");
    // DG.addEdge(0,1);
    // DG.addEdge(0,2);
    // DG.addEdge(1,3);
    // DG.addEdge(3,2);
    // DG.addEdge(2,1);

    cout << DG << endl;
    Digraph RDG = DG.reverse();
    cout << RDG;
}