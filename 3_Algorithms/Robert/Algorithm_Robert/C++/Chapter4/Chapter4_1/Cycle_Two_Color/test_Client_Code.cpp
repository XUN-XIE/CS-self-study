#include "Cycle_BFS.hpp"
// #include "CycleDetection.hpp"
#include "TwoColor.hpp"

int main()
{
    Graph graph("../tinyG.txt");
    // graph.addEdge(0,1);
    // graph.addEdge(2,1);
    // graph.addEdge(2,4);
    // graph.addEdge(3,2);
    // graph.addEdge(3,4);
    // graph.addEdge(3,5);
    // graph.addEdge(0,5);
    // graph.addEdge(0,2);
    // graph.addEdge(1,2);

    Cycle cycle(graph);
    cout << cycle.HasCycle() << endl;

    TwoColor color(graph);
    cout << color.isBipartite() << endl;
}