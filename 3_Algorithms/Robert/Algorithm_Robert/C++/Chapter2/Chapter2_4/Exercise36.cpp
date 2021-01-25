#include "PriorityQueue.hpp"

int main()
{
    for (int size = 1E4; size <= 1E6 + 1; size *= 2)
    {
        MaxPQ<int> PQ(1);
        
        double start = clock();
        // first insert
        for (int i = 0; i < size; i++)
            PQ.insert(rand());
        
        // remove half
        for (int i = 0; i < size / 2; i++)
            PQ.delMax();
        
        // second insert
        for (int i = 0; i < size / 2; i++)
            PQ.insert(rand());
        
        // remove all
        while (!PQ.isEmpty()) PQ.delMax();

        double end = clock();
        cout << "size " << size << " :" << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    }
}