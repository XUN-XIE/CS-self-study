#include "EdgeWeightedGraph.hpp"

int main()
{
    EdgeWeightedGraph EWG("tinyEWD.txt");
    cout << EWG << endl;

    EdgeWeightedGraph EWG2("tinyEWG.txt");
    EWG2 = EWG;
    cout << EWG2;

    vector<Edge> tmp = EWG.edges();
    cout << tmp.size() << endl;
}