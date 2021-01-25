#include "DirectedDFS.hpp"
#include "DirectedCycle.hpp"

int main()
{
    ifstream infile;
    infile.open("tinyDG.txt");

    int V, E;
    infile >> V >> E;
    Digraph DG(V);
    
    int v, w;
    for (int i = 0; i < E; i++)
    {
        infile >> v >> w;
        DG.addEdge(v, w);
    }

    vector<int> vec = {1,2,6};
    DirectedDFS DFS(DG, vec);

    for (int v = 0; v < DG.getV(); v++)
        if (DFS.hasPathTo(v))
            cout << v << " ";
    cout << endl;

    DirectedCycle cycle(DG);
    cout << cycle.hasCycle() << endl;
    
}