#include "../AllSort.hpp"

int count_partition(vector<int> & vec, int low, int high, int & count)
{
    int i = low, j = high + 1;
    int v = vec[low];
    while (true)
    {
        while (vec[++i] <= v) {count++; if (i == high) break;}
        while (v <= vec[--j]) {count++; if (j == low) break;}
        if (i >= j) {count++; break;}
        swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}

void count_QuickSort(vector<int> & vec, int low, int high, int & count)
{
    if (high <= low) return ;
    int j = count_partition(vec, low, high, count);
    count_QuickSort(vec, low, j-1, count);
    count_QuickSort(vec, j+1, high, count);
}

void count_QuickSort(vector<int> & vec)
{
    // random_shuffle(vec.begin(), vec.end());
    int count = 0;
    count_QuickSort(vec, 0, vec.size() - 1, count);

}

int main()
{
    for(int i = 100; i < 1E6+1; i *= 10)
    {
        test_algorithm(count_QuickSort, "Quadratic", i);
    }
}