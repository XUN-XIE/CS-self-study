#include "../AllSort.hpp"

void median_QuickSort(vector<int> & vec, int low, int high)
{
    if (high <= low) return;
    int j = median_partition(vec, low, high);
    median_QuickSort(vec, low, j-1);
    median_QuickSort(vec, j+1, high);
}

void median_QuickSort(vector<int> & vec)
{
    median_QuickSort(vec, 0, vec.size() - 1);
}

int main()
{
    int size = 1E7;
    test_algorithm(median_QuickSort, "sentinel", size);
    test_algorithm(QuickSort, "normal  ", size);
}