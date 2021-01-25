#include "PriorityQueue.hpp"

int main()
{
    vector<int> vec = {90,80,70};
    MaxPQ<int> PQ(vec);
    cout << PQ.size() << endl;
    for (int i = 0; i < 8; i++)
    {
        PQ.insert(i+1);
        PQ.output();
        cout << PQ.isOrdered() << endl;
    }
    for(int i = 0; i < 7; i++)
    {
        PQ.delMax();
        PQ.output();
    }
}