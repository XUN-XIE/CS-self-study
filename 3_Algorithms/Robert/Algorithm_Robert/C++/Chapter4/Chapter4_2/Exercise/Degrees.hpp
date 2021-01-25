#include "../Digraph.hpp"

// Exercise 7
class Degrees
{
private:
    Digraph DG;
public:
    Degrees(Digraph & G)
    {
        DG = G;
    }

    int indegree(int v)
    {
        return distance(DG.reverse().get_adj(v).begin(), DG.reverse().get_adj(v).end());
    }

    int outdegree(int v)
    {
        return distance(DG.get_adj(v).begin(), DG.get_adj(v).end());
    }

    vector<int> sources()
    {
        vector<int> source;
        for (int v = 0; v < DG.getV(); v++)
            if (indegree(v) == 0)
                source.push_back(v);
        return source;
    }

    vector<int> sink()
    {
        vector<int> s;
        for (int v = 0; v < DG.getV(); v++)
            if (outdegree(v) == 0)
                s.push_back(v);
        return s;
    }

    bool isMap()
    {
        for (int v = 0; v < DG.getV(); v++)
        {
            auto adj_v = DG.get_adj(v);
            int count = 0;
            for (auto w = adj_v.cbegin(); w != adj_v.cend(); w++)
                if (*w != v)
                    count++;
            if (count != 1)
                return false;
        }
        return true;
    }
};