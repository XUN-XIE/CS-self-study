#include "MaxMinPQ.hpp"

int main()
{
    MaxMinPQ<int> PQ(5);
    for (int i = 0; i < 15; i++)
    {
        PQ.insert(1 + rand()%15);
        // PQ.output();
        // PQ.output("ax");
        // cout << "--------------------\n";
    }
    PQ.delMax();
    PQ.output();
    PQ.output("s");
    cout << "--------------------\n";
    // PQ.delMin();
    // PQ.output();
    // PQ.output("s");
}