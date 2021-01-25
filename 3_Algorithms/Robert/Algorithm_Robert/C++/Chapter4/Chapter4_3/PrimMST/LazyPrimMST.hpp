#include "PriorityQueue.hpp"
#include "../EdgeWeightedGraph.hpp"

class LazyPrimMST
{
private:
    bool * marked;      // MST vertices
    queue<Edge> mst;    // MST edges
    MinPQ<Edge> pq;     // crossing (and ineligible) edges

    void visit(EdgeWeightedGraph & G, int v)
    {
        // Mark v and add to pq all edges from v to unmarked vertices
        marked[v] = true;
        for (Edge e : G.get_adj(v))
            if (!marked[e.other(v)])
                pq.insert(e);
    }
public:
    LazyPrimMST(EdgeWeightedGraph & G)
    {
        int V = G.getV();
        marked = new bool[V];

        visit(G, 0);            // assume G is connected
        while (!pq.isEmpty())
        {
            Edge e = pq.delMin();       // Get lowest-weight
            int v = e.either(), w = e.other(v);     // edge from pq
            if (marked[v] && marked[w]) continue;   // Skip if ineligible
            mst.push(e);                       // Add edge to tree
            if (!marked[v]) visit(G, v);        // Add vertex to tree
            if (!marked[w]) visit(G, w);        // (either v or w)
        }
    }

    ~LazyPrimMST() {   delete [] marked;   }

    queue<Edge> edges()    {   return mst; }

    // double weight()
    // {

    // }
};