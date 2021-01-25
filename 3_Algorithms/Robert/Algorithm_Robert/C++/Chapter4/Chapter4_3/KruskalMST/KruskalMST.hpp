#include "../EdgeWeightedGraph.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

// UnionFind 里的 union_together method 还没有实现
class KruskalMST
{
private:
    queue<Edge> mst;

public:
    KruskalMST(EdgeWeightedGraph & G)
    {
        MinPQ<Edge> pq(G.getE() + 1);
        vector<Edge> tmp = G.edges();
        for (int i = 0; i < tmp.size(); i++)
            pq.insert(tmp[i]);
        UF uf(G.getV());

        while (!pq.isEmpty() && mst.size() < G.getV() - 1)
        {
            Edge e = pq.delMin();               // Get min weight edge on pq and its verices
            int v = e.either(), w = e.other(v);
            if (uf.connected(v, w)) continue;   // Ignore ineligible edges
            uf.union_together(v, w);                     // Merge components
            mst.push(e);                        // Add edge to mst
        }

    }

    queue<Edge> edges()  {   return mst; }

    // double weight()
    // {

    // }
};