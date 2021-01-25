#include "../Graph.hpp"

class Cycle
{
private:
    bool * marked;
    bool hasCycle;

    void bfs(Graph & G, int v, int u)
    {
        queue<int> que;
        que.push(v);
        marked[v] = true;

        while (!que.empty())
        {
            int front = que.front(); que.pop();
            auto adj_v = G.get_adj(front);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            {
                if (!marked[*w])
                {
                    marked[*w] = true;
                    que.push(*w);
                }
                else if (*w != u)
                    hasCycle = true;
            }
            u = front;
        }
    }

public:
    Cycle(Graph & G)
    {
        marked = new bool[G.getV()];
        for (int s = 0; s < G.getV(); s++)
            if (!marked[s])
                bfs(G, s, s);
    }

    ~Cycle()    {   delete [] marked;   }

    bool HasCycle() {   return hasCycle;    }

};