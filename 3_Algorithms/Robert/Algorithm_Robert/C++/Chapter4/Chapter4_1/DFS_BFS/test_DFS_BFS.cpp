#include "BreadthFirstPaths.hpp"
#include "DepthFirstPaths.hpp"

// DFS 和 BFS 不能同时调用！！！不然graph会出现段错误
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

    BreadthFirstPaths BFS(graph, 0);
    // DepthFirstPaths   DFS(graph, 0);
    auto output1 = BFS.pathTo(4);
    // auto output2 = DFS.pathTo(4);

    cout << BFS.hasPathTo(4) << endl;
    // cout << DFS.hasPathTo(4) << endl;

    print(output1);
    // print(output2);

    cout << BFS.distTo(2) << endl;
    cout << BFS.distTo(3) << endl;
}