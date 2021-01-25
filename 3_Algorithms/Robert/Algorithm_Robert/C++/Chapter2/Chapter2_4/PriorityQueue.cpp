#include "PriorityQueue.hpp"

int main()
{
    MaxPQ<int> PQ(5);
    int val;
    while (cin >> val)
    {
        PQ.insert(val);
    }
    for (int i = 0; i < 5; i++)
        PQ.delMax();
    PQ.output();
    // for (int i = 0; i < 100; i++)
    // {
    //     PQ.insert(1 + rand()%50);
    //     // PQ.output();
    //     // cout << PQ.isOrdered() << endl;
    // }
    // PQ.output();
    // // cout << PQ.min() << endl;


    // for(int i = 0; i < 7; i++)
    // {
    //     PQ.delMax();
    //     PQ.output();
    // }

    // MinPQ<int> PQ(5);
    // for (int i = 0; i < 8; i++)
    // {
    //     PQ.insert(i+1);
    //     PQ.output();
    //     cout << PQ.isOrdered() << endl;
    // }
    // for(int i = 0; i < 7; i++)
    // {
    //     PQ.delMin();
    //     PQ.output();
    // }

}