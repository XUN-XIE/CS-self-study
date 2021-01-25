#ifndef EDGE_HPP
#define EDGE_HPP
#include <bits/stdc++.h>
using namespace std;

class Edge
{
private:
    int v;
    int w;
    double weight;

public:
    Edge() : v(-1), w(-1), weight(-1) { }
    Edge(int V, int W, double Weight) : v(V), w(W), weight(Weight) { }

    double get_weight() {   return weight;  }

    int either()    {   return v;   }

    int other(int vertex)
    {
        if      (vertex == v)    return w;
        else if (vertex == w)    return v;
        else
        {
            cerr << "Inconsistent edge\n";
            exit(-1);
        }
    }

    bool operator<(const Edge & other)  {   return weight < other.weight;   }
    bool operator>(const Edge & other)  {   return weight > other.weight;   }
    bool operator==(const Edge & other)  {   return weight == other.weight;   }
    bool operator<=(const Edge & other)  {   return weight <= other.weight;   }
    bool operator>=(const Edge & other)  {   return weight >= other.weight;   }

    int compareTo(const Edge & that)
    {
        if (weight < that.weight)       return -1;
        else if (weight > that.weight)  return 1;
        else                            return 0;
    }

    friend ostream & operator<<(ostream & os, const Edge & target)
    {
        os << target.v << "-" << target.w << " " << target.weight;
        return os;
    }
};

#endif