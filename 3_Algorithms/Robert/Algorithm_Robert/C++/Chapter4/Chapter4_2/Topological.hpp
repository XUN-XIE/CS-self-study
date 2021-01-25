#ifndef TOPOLOGICAL_HPP
#define TOPOLOGICAL_HPP
#include "DirectedCycle.hpp"
#include "DepthFirstOrder.hpp"

class Topological
{
private:
    stack<int> order;
public:
    Topological(Digraph & G)
    {
        DirectedCycle  cyclefinder(G);
        if (!cyclefinder.hasCycle())
        {
            DepthFirstOrder dfs(G);
            order = dfs.get_reversePost();
        }
    }

    stack<int> get_order()  {   return order;   }
};

#endif