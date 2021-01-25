#include "Graph.hpp"

// 见答案
// Exercise 36
class Bridge
{
private:
    int bridges;    // number of bridges
    int cnt;        // counter
    int * pre;      // pre[v] = order in which dfs examines v
    int * low;      // low[v] = lowest preorder of any vertex connected to v

    // v 表示当前点， u表示上一个点
    void dfs(Graph & G, int u, int v)
    {
        // 相当于，在每一个 cycle 里所有的Node的low值一样
        // 但是当通过 bridge 之后，另一个 subgraph 的 low 值一样，但是与之前的 subgraph 不一致
        pre[v] = cnt++;
        low[v] = pre[v];
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (pre[*w] == -1)
            {
                // 这里的 DFS 调用顺序 和 原始的DFS就不一样了！
                // *w 下一个点的位置位于第二
                dfs(G, v, *w);

                // 主要操作都在递归之后，所以是回溯过程进行判断
                low[v] = low[v] < low[*w] ? low[v] : low[*w];
                if (low[*w] == pre[*w])
                {
                    cout << v  << "-" << *w << " is a bridge" << endl;
                    bridges++;
                }
            }
            // update low number - ignore reverse of edge leading to v
            // 当 递归第一次进入后， 第二个点不会处理 第一个点 ！！！！
            // 能处理 第一个出发点的 ，只有每个 cycle 的与出发点相连的尾点
            else if (*w != u)
                low[v] = low[v] < pre[*w] ? low[v] : pre[*w];
    }

public:
    Bridge(Graph & G)
    {
        cnt = 0;
        int V = G.getV();
        low = new int[V];
        pre = new int[V];
        for (int v = 0; v < V; v++)
        {
            low[v] = -1;
            pre[v] = -1;
        }
        for (int v = 0; v < V; v++)
            if (pre[v] == -1)
                dfs(G, v, v);
    }

    int components()    {   return bridges + 1; }
};