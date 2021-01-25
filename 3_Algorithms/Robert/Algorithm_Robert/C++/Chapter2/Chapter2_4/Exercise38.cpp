#include "PriorityQueue.hpp"
#include "../AllSort.hpp"
int main()
{
    for (int size = 1E4; size <= 1E7 + 1; size *= 2)
    {
        vector<int> vec = produce(size);
        double start = clock();
        MaxPQ<int> PQ(vec);
        double end = clock();
        cout << "size " << size << " :" << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    }
}