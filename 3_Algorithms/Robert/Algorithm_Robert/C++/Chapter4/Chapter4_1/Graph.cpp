#include "Graph.hpp"

int main()
{
    Graph graph("tinyG.txt");
    // graph.addEdge(1,2);
    // graph.addEdge(2,3);
    // graph.addEdge(1,4);
    // graph.addEdge(2,1);
    forward_list<int> v1 = graph.get_adj(1);
    cout << graph;

    // Exercise 4
    cout << graph.hasEdge(1,2) << endl;
    cout << graph.hasEdge(1,3) << endl;
}