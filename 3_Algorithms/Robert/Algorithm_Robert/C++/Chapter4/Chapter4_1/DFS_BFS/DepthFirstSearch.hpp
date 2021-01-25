#include "../Graph.hpp"

// 学习图里的递归时，注意和树的一些区别来理解
// 树里的递归一般都是直接调用递归函数
// 图里的递归是 循环 里进行递归调用！（所以在回溯阶段，相当于回退回到原来已经探索过的点）

// 思维想象：DFS，等同于展开成一个（错误的）树，从上一直向下探索，当最底层探索完
// 返回上一层，在上一层的基础上向下探索完毕后，再返回上一层，循环往复。（最后把这个树想象成图）
class DFS
{
private:
    bool * marked;
    int count;
    void dfs(Graph G, int v)
    {
        marked[v] = true;
        count++;
        auto adj_v = G.get_adj(v);

        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
        {
            if (!marked[*w])
                dfs(G, *w);
        }
    }
public:
    DFS(Graph G, int s)
    {
        marked = new bool[G.getV()];
        dfs(G, s);
    }

    ~DFS()  {   delete [] marked;   }

    bool mark(int w)    {   return marked[w];   }
    int get_count()         {   return count;   }
};