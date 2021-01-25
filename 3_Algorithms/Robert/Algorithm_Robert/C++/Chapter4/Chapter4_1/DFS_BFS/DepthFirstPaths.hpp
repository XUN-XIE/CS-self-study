#include "../Graph.hpp"

class DepthFirstPaths
{
private:
    bool * marked;
    // 注意这个edgeTo是反着搜索方向进行记录的(因为正向记录的话，会存在冲突点)
    // 所以 source 点没有设置 edgeTo 的值
    int * edgeTo;
    int s;
    void dfs(Graph & G, int v)
    {
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
            {
                edgeTo[*w] = v;
                dfs(G, *w);
            }
    }
public:
    DepthFirstPaths(Graph & G, int ss)
    {
        marked = new bool[G.getV()];
        edgeTo = new int[G.getV()];
        s = ss;
        dfs(G, s);
    }

    ~DepthFirstPaths()
    {
        delete [] marked;
        delete [] edgeTo;
    }

    bool hasPathTo(int v)   {   return marked[v];   }

    stack<int> pathTo(int v)
    {
        if (!hasPathTo(v))  return stack<int>();
        stack<int> path;
        for (int x = v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
};