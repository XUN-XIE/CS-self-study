#include "../../DFS_BFS/BreadthFirstPaths.hpp"
#include "../../Cycle_Two_Color/CycleDetection.hpp"

class GraphProperties
{
    Graph graph;
    bool * marked;
    bool hasCycle;

public:
    GraphProperties(Graph G)
    {
        graph = G;
        marked = NULL;
    }

    int eccentricity(int v)
    {
        int further = 0;
        BreadthFirstPaths BFS(graph, v);
        for (int i = 0; i < graph.getV(); i++)
        {   
            int tmp = BFS.distTo(i);
            if ( tmp > further)
                further = tmp;
        }
        return further;
    }

    int diameter()
    {
        int maximum = 0;
        for (int i = 0; i < graph.getV(); i++)
        {
            int tmp = eccentricity(i);
            if (tmp > maximum)
                maximum = tmp;
        }
        return maximum;
    }

    int radius()
    {
        int minimum = INT_MAX;
        for (int i = 0; i < graph.getV(); i++)
        {
            int tmp = eccentricity(i);
            if (tmp < minimum)
                minimum = tmp;
        }
        return minimum;
    }

    vector<int> center()
    {
        vector<int> result;
        int r = radius();
        for (int i = 0; i < graph.getV(); i++)
        {
            int tmp = eccentricity(i);
            if (tmp == r)
                result.push_back( i );
        }
        return result;
    }

    // void dfs(Graph & G, int v, int u, int & count)
    // {
    //     marked[v] = true;
    //     auto adj_v = G.get_adj(v);
    //     count++;
    //     for (auto w = adj_v.begin(); w != adj_v.end(); w++)
    //     {
    //         if (!marked[*w])
    //             dfs(G, *w, v, count);
    //         else if (*w != u)
    //             return;
    //     }
    // }

    // int girth()
    // {
    //     Cycle cycle(graph);
    //     if (!cycle.HasCycle())
    //         return INFINITY;
        
    //     int length = INFINITY;
    //     int count = 0;
    //     int min = INFINITY;
    //     for (int v = 0; v < graph.getV(); v++)
    //     {
    //         marked = new bool[graph.getV()];
    //         hasCycle = false;
    //         dfs(graph, v, v, count);
    //         if (hasCycle && count < min)
    //             min = count;
    //         count = 0;
    //         delete [] marked;
    //     }
    //     return min;
    // }

    int bfs(Graph & G, int v, int u, vector<int> & count)
    {
        queue<int> que;
        que.push(v);
        marked[v] = true;
        int now_count = 0;
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
                    count[*w] = now_count++;
                }
                else if (*w != u)
                // 因为是 BFS，所以能够搜索到的第一个cycle，必定是最小的cycle！
                    return count[*w] - count[u];
            }
            u = front;
        }
        // 没有cycle
        return INFINITY;
    }

    int girth()
    {
        marked = new bool[graph.getV()];
        int min = INFINITY;
        int cur_num;
        for (int s = 0; s < graph.getV(); s++)
        {
            vector<int> count(graph.getV(), 0);
            if (!marked[s])
                cur_num = bfs(graph, s, s, count);
            if (cur_num < min)
                min = cur_num;
        }
        return min + 1;
    }
};