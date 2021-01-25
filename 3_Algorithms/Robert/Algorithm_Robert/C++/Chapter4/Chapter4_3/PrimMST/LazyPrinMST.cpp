#include "LazyPrimMST.hpp"

int main()
{
    EdgeWeightedGraph EWG("../tinyEWG.txt");
    LazyPrimMST mst(EWG);
    queue<Edge> que = mst.edges();
    while (!que.empty())
    {
        cout << que.front() << endl;
        que.pop();
    }
}