#include "../Graph.hpp"

class CC
{
private:
    bool * marked;
    int  * id;
    int count;
    int V;

    void dfs(Graph & G, int v)
    {
        marked[v] = true;

        // indicate the component id that this node belongs to
        id[v] = count;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
                dfs(G, *w);
    }
public:
    CC(Graph & G)
    {
        count = 0;
        V = G.getV();
        marked = new bool[V];
        id = new int[V];
        for (int s = 0; s < V; s++)
        // 一次调用，代表查找一个 connected component，所以count++放在这里
            if (!marked[s])
            {
                dfs(G, s);
                count++;
            }   
    }

    ~CC()   {   delete [] marked; delete [] id; }

    bool connected(int v, int w)    {   return id[v] == id[w];  }

    int get_id(int v)   {   return id[v];   }

    int get_count() {   return count;   }
};