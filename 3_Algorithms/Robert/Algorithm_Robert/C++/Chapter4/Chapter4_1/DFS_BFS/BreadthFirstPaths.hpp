#include "../Graph.hpp"


// Mention 但凡传入 Graph 对象的function method都要使用 引用 ！！！
// 原因，因为C++ 在函数传入对象时，会调用 copy constructor，但是因为 class Graph 没有定义
// 所以 如果不加引用，会出现内存泄漏

// 思想解读：BFS，同样的想象（错误的）一个树，这一次从root出发，每次逐层探索，每一层探索完了之后，才进入下一层的探索
class BreadthFirstPaths
{
private:
    bool * marked;
    int * edgeTo;
    int s;

    // Exercise 13
    int * dist;

    // either pass class Graph by value or pass it by reference, both is Ok for I have written copy constructor
    void bfs(Graph & G, int s)
    {
        queue<int> que;
        marked[s] = true;
        que.push(s);
        dist[s] = 0;
        while (!que.empty())
        {
            int v = que.front(); que.pop();
            auto adj_v = G.get_adj(v);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
                if (!marked[*w])
                {
                    edgeTo[*w] = v;
                    marked[*w] = true;
                    dist[*w] = dist[v] + 1;
                    que.push(*w);
                }
        }
    }

public:
    BreadthFirstPaths()
    {
        marked = NULL;
        edgeTo = NULL;

        // Exercise 13
        dist = NULL;
    }

    BreadthFirstPaths(Graph & G, int ss)
    {
        marked = new bool[G.getV()];
        edgeTo = new int[G.getV()];

        // Exercise 13
        dist = new int[G.getV()];
        for (int i = 0; i < G.getV(); i++)
            dist[i] = -1;
        s = ss;
        bfs(G, s);
    }

    ~BreadthFirstPaths()
    {
        if (marked != NULL)
            delete [] marked;
        if (edgeTo != NULL)
            delete [] edgeTo;
        if (dist != NULL)
            delete [] dist;
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

    int distTo(int v)
    {
        return dist[v];
    }
};