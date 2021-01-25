#ifndef GRAGP_HPP
#define GRAGP_HPP
#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    int E;
    forward_list<int> * adj;

public:
    Graph() {   adj = NULL; }

    Graph(int v)
    {
        V = v;
        E = 0;
        adj = new forward_list<int>[V];
    }

    Graph(string filename, char sp = ' ')
    {
        ifstream infile;
        infile.open(filename);
        if (!infile.is_open())
        {
            cerr << "the file is not exist\n";
            exit(-1);
        }
        string tmp;
        getline(infile, tmp);
        V = stoi(tmp);
        getline(infile, tmp);
        E = stoi(tmp);
        adj = new forward_list<int>[V];
        while (getline(infile, tmp))
        {
            int first = tmp.find(sp, 0);
            tmp.substr(0, first);
            int root = stoi(tmp.substr(0, first));

            int next_pos = first;
            int child;
            while (next_pos < tmp.length())
            {
                int cur = next_pos + 1;
                next_pos = tmp.find(sp, cur);
                child = stoi(tmp.substr(cur, next_pos - cur));
                adj[root].push_front(child);
            }
        }
        infile.close();
    }

    // copy constructor.
    // if you want to pass class Graph to function by value
    Graph(const Graph & G)
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

    Graph & operator=(const Graph & G)
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

    ~Graph()    {   delete [] adj;  }

    int getV() {   return V;   }
    int getE() {   return E;   }

    void addEdge(int v, int w)
    {
        // Exercise 5
        if (v == w)
            return ;
        // if (hasEdge(v, w))
        //     return ;

        adj[v].push_front(w);
        adj[w].push_front(v);
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

    friend ostream &operator<<( ostream & output, const Graph & G)
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

#endif