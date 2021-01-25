#ifndef EDGEWEIGHTEDGRAPH_HPP
#define EDGEWEIGHTEDGRAPH_HPP
#include "Edge.hpp"

class EdgeWeightedGraph
{
private:
    int V;
    int E;
    vector<Edge> * adj;

public:
    EdgeWeightedGraph(int v)
    {
        V = v;
        E = 0;
        adj = new vector<Edge>[V];
    }
    
    EdgeWeightedGraph(const EdgeWeightedGraph & G)
    {
        V = G.V;
        E = G.E;

        if (G.adj == NULL)
            adj = NULL;
        else
        {
            adj = new vector<Edge>[V];
            for (int i = 0; i < V; i++)
                adj[i] = G.adj[i];
        }
    }

    EdgeWeightedGraph & operator=(const EdgeWeightedGraph & G)
    {
        V = G.V;
        E = G.E;

        auto nep = new vector<Edge>[V];
        delete [] adj;
        
        for (int i = 0; i < V; i++)
            nep[i] = G.adj[i];
        adj = nep;

        return *this;
    }

    EdgeWeightedGraph(string filename)
    {
        ifstream infile;
        infile.open(filename);
        if (!infile.is_open())
        {
            cerr << "file is not open\n";
            exit(-1);
        }
        infile >> V >> E;
        adj = new vector<Edge>[V];

        int val1, val2;
        double val3;
        while (infile >> val1 >> val2 >> val3)
        {
            Edge tmp(val1, val2, val3);
            addEdge(tmp);
        }
        infile.close();
    }

    int getV()  {   return V;   }
    int getE()  {   return E;   }

    void addEdge(Edge e)
    {
        int v = e.either(), w = e.other(v);
        adj[v].push_back(e);
        adj[w].push_back(e);
        E++;
    }

    vector<Edge> get_adj(int v) {   return adj[v];  }

    vector<Edge> edges()
    {
        vector<Edge> b;
        for (int v = 0; v < V; v++)
            for (Edge e: adj[v])
                if (e.other(v) > v)
                    b.push_back(e);
        return b;
    }

    friend ostream & operator<<(ostream & os, const EdgeWeightedGraph & EWG)
    {
        for (int i = 0; i < EWG.V; i++)
        {
            os << "Vertex " << i << ":    ";
            for (Edge E : EWG.adj[i])
                os << E << "\t";
            cout << endl;
        }
        return os;
    }
};
#endif