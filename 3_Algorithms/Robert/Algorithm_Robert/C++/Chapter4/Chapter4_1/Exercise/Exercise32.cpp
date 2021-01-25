#include "../Graph.hpp"

// 要先修改 Graph 可以支持 parallel 
class ParallelDetection
{
private:
    Graph G;

public:
    ParallelDetection(Graph & g)
    {
        G = g;
    }

    int getP()
    {
        int countP = 0;
        for (int v = 0; v < G.getV(); v++)
        {
            auto adj_v = G.get_adj(v);
            for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            {
                if (count(adj_v.begin(), adj_v.end(), *w) > 1)
                    countP++;
            }
        }
        return countP / 2;
    }
};

int main()
{
    Graph graph(3);
    graph.addEdge(0,1);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    cout << graph;
    ParallelDetection PD(graph);
    cout << PD.getP() << endl;
}