#include "../Graph.hpp"

class Cycle
{
private:
    bool * marked;
    bool hasCycle;

    void dfs(Graph & G, int v, int u)
    {
        // v = 当前访问 Node
        // u 是 访问 v 之前的 上一次 访问 Node

        // 理解， 假设 图结构 就是一个单线圈，每次沿着一个方向
        // 递归调用，v 和 u 每次沿着该方向前移，直到最后的 v 遇到了最开始访问的结点 s（or 0）
        // 就会通过 else if 中的判断条件 *w ！= u，然后找到了 Cycle！！！
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
        {
            if (!marked[*w])
            // 正常的 DFS 调用就是传入 G 和 *w，而这里多加了一个记录上一次探索的点
                dfs(G, *w, v);
            // 这里表示，正常情况下，相对于当前点，如果 出现了marked的点，那么肯定是上一次探索的点(父点)
            // 但是如果出现了 子点和父点 不同！ 那么就说明，前方出现了一个未探索却 marked 的点，所以肯定是cycle了
            else if (*w != u)
                hasCycle = true;
        }
    }

public:
    Cycle(Graph & G)
    {
        marked = new bool[G.getV()];
        for (int s = 0; s < G.getV(); s++)
            if (!marked[s])
                dfs(G, s, s);
    }

    ~Cycle()    {   delete [] marked;   }

    bool HasCycle() {   return hasCycle;    }

};