#include "../Graph.hpp"

class TwoColor
{
private:
    bool * marked;
    bool * color;
    bool isTwoColorable = true;

    void dfs(Graph & G, int v)
    {
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
        {
            if (!marked[*w])
            {
                color[*w] = !color[v];
                dfs(G, *w);
            }
            else if (color[*w] == color[v])
                isTwoColorable = false;
        }
    }
public:
    TwoColor(Graph & G)
    {
        marked = new bool[G.getV()];
        color = new bool[G.getV()];
        for (int s = 0; s < G.getV(); s++)
            if (!marked[s])
                dfs(G, s);
    }

    bool isBipartite()  {   return isTwoColorable;  }
};