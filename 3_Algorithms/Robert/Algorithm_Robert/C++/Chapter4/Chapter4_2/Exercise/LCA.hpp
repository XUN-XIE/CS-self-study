#include "../Digraph.hpp"

class LCA
{
private:
    Digraph DG;
    int * height;
    bool * marked;

    void bfs(Digraph & DG, int v)
    {
        queue<int> que;
        que.push(v);
        marked[v] = true;
        height[v] = 0;
        while (!que.empty())
        {
            int front = que.front();    que.pop();
            auto adj_v = DG.get_adj(front);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            {
                if (!marked[*w])
                {
                    marked[*w] = true;
                    que.push(*w);
                    height[*w] = height[v] + 1;
                }
            }
        }
    }
public:
    LCA(Digraph & dg)
    {
        DG = dg;
        height = new int[DG.getV()];
        marked = new bool[DG.getV()];

        for (int i = 0; i < DG.getV(); i++)
            if (!marked[i])
                bfs(DG, i);
    }

    int getLCA(int s, int v)
    {
        int maxLCA = 0;
        for (int i = 0; i < DG.getV(); i++)
        {
            bool foundS = false, foundV = false;
            auto adj_v = DG.get_adj(i);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            {
                if ( *w == s )
                    foundS = true;
                if ( *w == v )
                    foundV = true;
            }

            if (foundS && foundV)
                maxLCA = height[i] > maxLCA ? height[i] : maxLCA;
        }
        return maxLCA;
    }

};