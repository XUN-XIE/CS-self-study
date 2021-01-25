#include "PriorityQueue.hpp"
#include "../EdgeWeightedGraph.hpp"
#include "IndexMinPQ.hpp"

// 这个算法还没测试成功，据本次估计，是IndexMinPQ实现有问题！！！

// eas=ger version which is better than lazy version
class PrimMST
{
private:
    Edge * edgeTo;          // shortest edge from tree vertex
    double * distTo;        // distTo[w] = edgeTo[w].weight
    bool * marked;          // true if v on tree
    IndexMinPQ<double> * pq;    // eligible crossing edges
    int V;

    void visit(EdgeWeightedGraph & G, int v)
    {
        // Add v to tree; update data structure
        marked[v] = true;
        for (Edge & e : G.get_adj(v))
        {
            int w = e.other(v);
            if (marked[w]) continue;    // v-w is ineligible
            if (e.get_weight() < distTo[w])
            {
                // Edge e is new best connection from tree to w
                edgeTo[w] = e;
                distTo[w] = e.get_weight();
                if (pq->contains(w))    pq->change(w, distTo[w]);
                else                    pq->insert(w, distTo[w]);
            }
        }
    }
public:
    PrimMST(EdgeWeightedGraph & G)
    {
        V = G.getV();
        edgeTo = new Edge[V];
        distTo = new double[V];
        marked = new bool[V];
        for (int v = 0; v < V; v++)
            distTo[v] = INFINITY;
        pq = new IndexMinPQ<double>(V);

        distTo[0] = 0.0;
        pq->insert(0, 0.0);      // Initialize pq with 0, weight 0.
        while (!pq->isEmpty())
            visit(G, pq->delMin());  // Add closest vertex to tree
    }

    queue<Edge> edges()
    {
        queue<Edge> result;
        for (int i = 0; i < V; i++)
            if (marked[i])
                result.push(edgeTo[i]);
        return result;
    }

    // double weight()
    // {

    // }
};