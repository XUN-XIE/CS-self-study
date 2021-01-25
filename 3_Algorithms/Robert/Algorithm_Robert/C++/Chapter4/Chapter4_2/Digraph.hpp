#ifndef DIGRAGP_HPP
#define DIGRAGP_HPP
#include <bits/stdc++.h>
using namespace std;

class Digraph
{
private:
    int V;
    int E;
    forward_list<int> * adj;
public:
    Digraph() {   adj = NULL; }

    Digraph(int v)
    {
        V = v;
        E = 0;
        adj = new forward_list<int>[V];
    }

    Digraph(string filename)
    {
        ifstream infile;
        infile.open(filename);
        if (!infile.is_open())
        {
            cerr << "the file is not exist\n";
            exit(-1);
        }
        infile >> V >> E;
        adj = new forward_list<int>[V];
        int val1, val2;
        while (infile >> val1 >> val2)
        {
            if (find(adj[val1].begin(), adj[val1].end(), val2) == adj[val1].end() && val1 != val2)
                adj[val1].push_front(val2);
        }
        infile.close();
    }

    // copy constructor.
    // if you want to pass class Graph to function by value
    Digraph(const Digraph & G)
    {
        V = G.V;
        E = G.E;

        if (G.adj == NULL)
            adj = NULL;
        else
        {
            adj = new forward_list<int>[V];
            for (int i = 0; i < V; i++)
                adj[i] = G.adj[i];
        }
    }

    Digraph & operator=(const Digraph & G)
    {
        V = G.V;
        E = G.E;

        auto nep = new forward_list<int>[V];
        delete [] adj;
        
        for (int i = 0; i < V; i++)
            nep[i] = G.adj[i];
        adj = nep;

        return *this;
    }

    ~Digraph()    {   delete [] adj;  }

    int getV() {   return V;   }
    int getE() {   return E;   }

    void addEdge(int v, int w)
    {
        // Exercise 5
        if (v == w)
            return ;
        if (hasEdge(v, w))
            return ;
        if (find(adj[v].begin(), adj[v].end(), w) == adj[v].end() && v != w)
        adj[v].push_front(w);
        E++;
    }

    forward_list<int> get_adj(int  v)   {   return adj[v];  }

    // Exercise 4
    bool hasEdge(int v, int w)
    {
        auto list1 = adj[v];
        if (find(list1.begin(), list1.end(), w) != list1.end())
            return true;
        return false;
    }

    Digraph reverse()
    {
        Digraph R(V);
        for (int v = 0; v < V; v++)
        {
            for (int w : adj[v])
                R.addEdge(w, v);
        }
        return R;
    }

    friend ostream &operator<<( ostream & output, const Digraph & G)
    {
        output << G.V << " vertices, " << G.E << " edges\n";
        for (int v = 0; v < G.V; v++)
        {
            output << v << ": ";
            auto adj_v = G.adj[v];
            for (auto w = adj_v.cbegin(); w != adj_v.cend(); w++)
                output << *w << " ";
            output << endl;
        }
        return output;
    }

    // Exercise 4
    bool PathTo(int s, int t)
    {
        // apply BFS to search
        queue<int> que;
        que.push(s);

        bool marked[V];
        marked[s] = true;

        while (!que.empty())
        {
            int front = que.front(); que.pop();
            auto adj_v = adj[front];
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            {
                if (*w == t)
                    return true;
                else if (!marked[*w])
                {
                    marked[*w] = true;
                    que.push(*w);
                }
            }
        }
        return false;
    }
};




// for print out the adjacent vertices of the given vertex
void print(forward_list<int> target)
{
    if (target.empty()) return;
    auto cur = target.begin();
    while (cur != target.end())
    {
        cout << *cur << " ";
        cur++;
    }
    cout << endl;
}

// for print out the reuslt of the DepthFirstPaths
void print(stack<int> target)
{
    if (target.empty()) return;
    while (!target.empty())
    {
        cout << target.top() << " ";
        target.pop();
    }
    cout << endl;
}

// for print out the reuslt of the DepthFirstOrder
void print(queue<int> target)
{
    if (target.empty()) return;
    while (!target.empty())
    {
        cout << target.front() << " ";
        target.pop();
    }
    cout << endl;
}

#endif