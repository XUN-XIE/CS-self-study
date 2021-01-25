#include "../DirectedCycle.hpp"
#include "Degrees.hpp"

// Exercise 20
bool DirectedEulerianCycle(Digraph & DG)
{
    DirectedCycle DC(DG);
    if (!DC.hasCycle())
        return false;
    
    Degrees degree(DG);
    for (int i = 0; i < DG.getV(); i++)
        if (degree.indegree(i) != degree.outdegree(i))
            return false;
    return true;
}

int main()
{
    Digraph DG("../tinyDG.txt");
    cout << DirectedEulerianCycle(DG) << endl;
}