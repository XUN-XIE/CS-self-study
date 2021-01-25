#include "Bridge.hpp"

int main()
{
    Graph graph(6);

    // // non-bridge case
    // graph.addEdge(0,1);
    // graph.addEdge(2,1);
    // graph.addEdge(2,4);
    // graph.addEdge(3,2);
    // graph.addEdge(3,4);
    // graph.addEdge(3,5);
    // graph.addEdge(0,5);
    // graph.addEdge(0,2);
    // graph.addEdge(1,2);

    // test case 2，bridge case
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(0,2);

    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(5,4);

    graph.addEdge(2,3);

    Bridge bridge(graph);
    cout << "Edge connected components = " << bridge.components() << endl;
}