#include "../Topological.hpp"
#include "../DirectedCycle.hpp"

bool Hamiltonian(Digraph & DG)
{
    DirectedCycle cycle(DG);
    Topological Top(DG);
    stack<int> sort_order = Top.get_order();
    // 说明不是 DAG
    if (sort_order.empty())
    {
        cerr << "not a DAG\n";
            return false;
    }
    while (!sort_order.empty())
    {
        int top = sort_order.top(); sort_order.pop();
        bool found_connectivity = false;
        auto adj_v = DG.get_adj(top);
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            if (*w == sort_order.top())
                found_connectivity = true;
        if (found_connectivity == false)
            return false;
    }
    return true;
}

int main()
{
    Digraph DG("../tinyDG.txt");
    cout << Hamiltonian(DG) << endl;
    // Topological Top(DG);
    // stack<int> sort_order = Top.get_order();
    // // 说明不是 DAG
    // if (sort_order.empty())
    //     return -1;
    // while (!sort_order.empty())
    // {
    //     int top = sort_order.top(); sort_order.pop();
    //     bool found_connectivity = false;
    //     auto adj_v = DG.get_adj(top);
    //     for (auto w = adj_v.begin(); w != adj_v.end(); w++)
    //         if (*w == sort_order.top())
    //             found_connectivity = true;
    //     if (found_connectivity == false)
    //     {
    //         cout << false << endl;
    //         return 0;
    //     }
    // }
    // cout << true << endl;
}
