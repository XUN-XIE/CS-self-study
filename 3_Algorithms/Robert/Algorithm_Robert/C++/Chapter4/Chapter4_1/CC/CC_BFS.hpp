#include "../Graph.hpp"

class CC
{
private:
    bool * marked;
    int  * id;
    int count;
    int V;

    void bfs(Graph & G, int v)
    {
        queue<int> que;
        que.push(v);
        marked[v] = true;
        id[v] = count;
        while (!que.empty())
        {
            int front = que.front(); que.pop();
            auto adj_v = G.get_adj(front);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
                if (!marked[*w])
                {
                    que.push(*w);
                    marked[*w] = true;
                    id[*w] = count;
                }
        }
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
                bfs(G, s);
                count++;
            }
    }

    ~CC()   {   delete [] marked; delete [] id; }

    bool connected(int v, int w)    {   return id[v] == id[w];  }

    int get_id(int v)   {   return id[v];   }

    int get_count() {   return count;   }
};