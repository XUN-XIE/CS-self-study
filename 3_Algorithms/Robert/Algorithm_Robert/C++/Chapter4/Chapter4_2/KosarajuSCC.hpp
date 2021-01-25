#include "DepthFirstOrder.hpp"

class KosarajuSCC
{
private:
    bool * marked;
    int  * id;
    int count;
    int V;

    void dfs(Digraph & G, int v)
    {
        marked[v] = true;
        id[v] = count;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
            {
                // // for print
                // cout << *w << " ";
                dfs(G, *w);
            }
    }
public:
    KosarajuSCC(Digraph & G)
    {
        V = G.getV();
        marked = new bool[V];
        id = new int[V];
        count = 0;
        // 应该是缺一个 constructor，所以不能直接在order的初始化中直接调用 （move constructor？？？）
        Digraph reversed = G.reverse();
        DepthFirstOrder order(reversed);
        auto revered_order = order.get_reversePost();
        // 与 unidirected graph的 不同点：
        // undirected graph 是顺序的进行 dfs 调用
        // Digrap 则是对 graph 的 reversePost 进行 dfs 调用！！！

        // 回忆 reversePost（CycleDetection里的用法）， 它可以把 同一条路径上的 Node，倒序压入stack（顺序出stack）
        // 然后调用 dfs，对从 某一个 component 的初始点开始遍历完所有该component点 
        while (!revered_order.empty())
        {
            auto s = revered_order.top(); revered_order.pop();
            if (!marked[s])
            {
                // // for print
                // cout << s << " ";
                dfs(G, s);
                count++;
                // // for print
                // cout << endl;
            }   
        }
    }

    ~KosarajuSCC()   {   delete [] marked; delete [] id; }

    bool sronglyConnected(int v, int w)    {   return id[v] == id[w];  }

    int get_id(int v)   {   return id[v];   }

    int get_count() {   return count;   }
};