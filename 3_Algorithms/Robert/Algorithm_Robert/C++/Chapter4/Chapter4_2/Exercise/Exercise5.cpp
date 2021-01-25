#include "../Digraph.hpp"

int main()
{
    Digraph DG(3);
    DG.addEdge(0,1);
    DG.addEdge(0,0);
    DG.addEdge(0,1);
    DG.addEdge(2,1);
    DG.addEdge(2,1);
    cout << DG << endl;
}