#include "Digraph.hpp"

class DirectedDFS
{
private:
    bool * marked;

    void dfs(Digraph & G, int v)
    {
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
                dfs(G, *w);
    }
public:
    DirectedDFS(Digraph & G, int s)
    {
        marked = new bool[G.getV()];
        dfs(G, s);
    }

    DirectedDFS(Digraph & G, vector<int> & sources)
    {
        marked = new bool[G.getV()];
        for (int s : sources)
            if (!marked[s])
                dfs(G, s);
    }

    ~DirectedDFS()
    {
        delete [] marked;
    }

    bool hasPathTo(int v)   {   return marked[v];   }

    // stack<int> pathTo(int v)
    // {
    //     if (!hasPathTo(v))  return stack<int>();
    //     stack<int> path;
    //     for (int x = v; x != s; x = edgeTo[x])
    //         path.push(x);
    //     path.push(s);
    //     return path;
    // }
};