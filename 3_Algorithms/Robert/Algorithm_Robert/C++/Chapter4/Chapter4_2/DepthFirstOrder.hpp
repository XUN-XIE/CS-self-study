#include "Digraph.hpp"

class DepthFirstOrder
{
private:
    bool * marked;
    queue<int> pre;             // vertices in preorder
    queue<int> post;            // vertices in postorder
    stack<int> reversePost;     // vertices in reverse postorder

    void dfs(Digraph & G, int v)
    {
        pre.push(v);
        marked[v] = true;
        auto adj_v = G.get_adj(v);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (!marked[*w])
                dfs(G, *w);
        post.push(v);
        reversePost.push(v);
    }
public:
    DepthFirstOrder(Digraph & G)
    { 
        pre = queue<int>();
        post = queue<int>();
        reversePost = stack<int>();

        int V = G.getV();
        marked = new bool[V];
        for (int v = 0; v < V; v++)
            if (!marked[v])
                dfs(G, v);
    }

    ~DepthFirstOrder()  
    {   
        delete [] marked;   
    }

    queue<int> get_pre()            {   return pre;         }
    queue<int> get_post()           {   return post;        }
    stack<int> get_reversePost()    {   return reversePost; }
};