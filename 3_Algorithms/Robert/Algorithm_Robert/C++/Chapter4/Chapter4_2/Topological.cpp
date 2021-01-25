#include "Topological.hpp"
#include "SymbolDigraph.hpp"

int main()
{
    SymbolDigraph SG("jobs.txt", "/");
    Digraph DG = SG.get_graph();
    Topological top(DG);

    stack<int> order = top.get_order();
    while (!order.empty())
    {
        cout << SG.name(order.top()) << endl;
        order.pop();
    }
}