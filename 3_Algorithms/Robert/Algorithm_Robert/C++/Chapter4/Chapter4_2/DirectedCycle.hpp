#ifndef DIRECTEDCYCLE_HPP
#define DIRECTEDCYCLE_HPP
#include "Digraph.hpp"

class DirectedCycle
{
private:
    bool * marked;
    int * edgeTo;
    stack<int> * cycle;         // vertices on a cycle (if one exists)
    bool * onStack;             // vertices on recursive call stack

    void dfs(Digraph & G, int v)
    {
        onStack[v] = true;
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
        {
            // 当 cycle 被赋值时，也说明存在循环图，所以直接退出
            if (hasCycle()) return;
            else if (!marked[*w])
            {
                // 反向记录 edge
                edgeTo[*w] = v;
                dfs(G, *w);
            }
            // 这说明一次 DFS 中，已经出现过的点，在后续的点的子点中，不能再次出现，否则说明构成 cycle。
            // 类似于 marked ！
            else if (onStack[*w])
            {
                cycle = new stack<int>();

                // 反向添加 edgeTo 中记录的路径。因此可以理解为 edgeTo 是为了辅助 cycle path 的输出的
                // 加入 stack 里， 取出时，自动倒序，因此最后得到的序列就是从出发点到出发点的前一点
                for (int x = v; x != *w; x = edgeTo[x])
                    cycle->push(x);
                cycle->push(*w);
                cycle->push(v);
            }
        }
        // 回溯过程 将 onstack 复原为 false （并不影响，单次的递归深入寻找 cycle）
        onStack[v] = false;
    }

public:
    DirectedCycle(Digraph & G)
    {
        cycle = NULL;
        int V = G.getV();
        onStack = new bool[V];
        edgeTo = new int[V];
        marked = new bool[V];
        for (int v = 0; v < V; v++)
            if (!marked[v])
                dfs(G, v);
    }

    ~DirectedCycle()
    {
        delete [] marked;
        delete [] edgeTo;
        delete cycle;
        delete [] onStack;
    }

    bool hasCycle() {   return cycle != NULL;    }

    stack<int> get_cycle()    {   return *cycle;   }
};

#endif