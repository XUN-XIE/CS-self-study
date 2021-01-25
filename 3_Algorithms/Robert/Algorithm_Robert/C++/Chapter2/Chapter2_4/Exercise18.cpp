#include "PriorityQueue.hpp"

int main()
{
    MaxPQ<int> PQ(5);
    for (int i = 0; i < 8; i++)
    {
        PQ.insert(i+1);
    }
    PQ.output();

    PQ.insert(9);
    PQ.insert(10);
    PQ.delMax();
    PQ.delMax();
    PQ.output();

}