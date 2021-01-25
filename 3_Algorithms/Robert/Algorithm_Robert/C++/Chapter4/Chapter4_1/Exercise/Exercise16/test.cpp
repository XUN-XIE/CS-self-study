#include "GraphProperties.hpp"

int main()
{
    Graph graph(6);
    graph.addEdge(0,1);
    graph.addEdge(2,1);
    graph.addEdge(2,4);
    graph.addEdge(3,2);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(0,5);
    graph.addEdge(0,2);
    graph.addEdge(1,2);

    GraphProperties test(graph);
    cout << test.eccentricity(0) << endl;
    cout << test.diameter() << endl;
    cout << test.radius() << endl;

    vector<int> centers = test.center();
    for (int i = 0; i < centers.size(); i++)
        cout << centers[i] << " ";
    cout << endl;

    cout << test.girth() << endl;
}