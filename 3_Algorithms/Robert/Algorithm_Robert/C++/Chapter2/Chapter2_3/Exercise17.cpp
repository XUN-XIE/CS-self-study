#include "../AllSort.hpp"

int sentinel_partition(vector<int> & vec, int low, int high)
{
    // 没用使用 std::max_element 因为测试结果反而更慢
    int max_index = low;
    for (int k = low; k <= high; k++ )
        max_index = vec[k] > vec[max_index] ? k : max_index;
    swap(vec[high], vec[max_index]);

    int i = low, j = high + 1;
    int v = vec[low];
    while (true)
    {
        while (vec[++i] < v);
        while (v < vec[--j]);
        if (i >= j) break;
        swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}

void sentinel_QuickSort(vector<int> & vec, int low, int high)
{
    if (high <= low) return;
    int j = sentinel_partition(vec, low, high);
    sentinel_QuickSort(vec, low, j-1);
    sentinel_QuickSort(vec, j+1, high);
}

void sentinel_QuickSort(vector<int> & vec)
{
    // random_shuffle(vec.begin(), vec.end());
    sentinel_QuickSort(vec, 0, vec.size() - 1);
}

int main()
{
    int size = 1E7;
    test_algorithm(sentinel_QuickSort, "sentinel", size);
    test_algorithm(QuickSort, "normal  ", size);
}