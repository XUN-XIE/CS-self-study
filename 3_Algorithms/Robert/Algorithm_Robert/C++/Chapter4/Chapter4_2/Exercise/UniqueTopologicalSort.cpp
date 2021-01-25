#include "../Topological.hpp"

bool uniqueTop(Digraph & DG, stack<int> & order)
{
    while (!order.empty())
    {
        int top = order.top();  order.pop();

        bool found = false;
        auto adj_top = DG.get_adj(top);
        for (auto w = adj_top.begin(); w != adj_top.end(); w++)
        {
            if (*w == order.top())
                found = true;
        }

        adj_top = DG.get_adj(order.top());
        for (auto w = adj_top.begin(); w != adj_top.end(); w++)
        {
            if (*w == top)
                found = true;
        }

        if (found == false)
            return false;
    }
    return true;
}

int main()
{
    Digraph DG("../tinyDG.txt");
    Topological Top(DG);
    stack<int> sort_order = Top.get_order();

    cout << uniqueTop(DG, sort_order) << endl;
}