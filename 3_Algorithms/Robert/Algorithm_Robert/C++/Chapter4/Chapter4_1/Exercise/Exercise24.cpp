#include "SymbolGraph.hpp"

void dfs(Graph & G, int v, int count, vector<bool> & marked)
    {
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
            {
                count++;
                dfs(G, *w, count, marked);
            }
    }

int maxComponentSize(Graph & G)
{
    vector<bool> marked(G.getV());
    int maximum = 0;
    for (int i = 0; i < G.getV(); i++)
    {
        int v = i;
        int count;
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
            {
                count++;
                dfs(G, *w, count, marked);
            }
        maximum = maximum > count ? maximum : count;
    }
    return maximum;
}

int ComonentSizeLess(Graph & G, int bound)
{
    vector<bool> marked(G.getV());
    int compoSize = 0;
    for (int i = 0; i < G.getV(); i++)
    {
        int v = i;
        int count;
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
            {
                count++;
                dfs(G, *w, count, marked);
            }
        if (count < bound)
            compoSize++;
    }
    return compoSize;
}

// 第二小问后面的都没做，因为不知道怎么拆分出最大的 component
int main()
{
    SymbolGraph sg("movies.txt", "/");
    Graph G = sg.get_graph();
    // cout << maxComponentSize(G) << endl;
    // cout << ComonentSizeLess(G, 10) << endl;
    GraphProperties GP(G);
}