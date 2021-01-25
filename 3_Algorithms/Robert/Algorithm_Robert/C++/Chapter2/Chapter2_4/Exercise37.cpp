#include "PriorityQueue.hpp"

int main()
{
    for (int size = 1E4; size <= 1E6 + 1; size *= 2)
    {
        MaxPQ<int> PQ(1);
        
        // first insert
        for (int i = 0; i < size; i++)
            PQ.insert(rand());
        
        double start = clock();
        int count = 0;
        while (clock() - start < 1000)
        {
            PQ.insert(rand());
            PQ.delMax();
            count++;
        }
        cout << "size " << PQ.size() << " :" << count << " times" << endl;
    }
}