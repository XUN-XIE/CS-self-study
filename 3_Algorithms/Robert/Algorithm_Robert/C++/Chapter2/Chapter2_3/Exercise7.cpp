#include "../AllSort.hpp"

int count_partition(vector<int> & vec, int low, int high, int & count)
{
    if (high - low <= 2)
        count++;
    int i = low, j = high + 1;
    int v = vec[low];
    while (true)
    {
        while (vec[++i] < v) { if (i == high) break;}
        while (v < vec[--j]) { if (j == low) break;}
        if (i >= j) { break;}
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

int count_QuickSort(vector<int> & vec)
{
    // random_shuffle(vec.begin(), vec.end());
    int count = 0;
    count_QuickSort(vec, 0, vec.size() - 1, count);
    return count;
}

int main()
{
    for(double i = 100; i < 1E7+1; i *= 10)
    {
        vector<int> vec = produce(i);
        cout << count_QuickSort(vec) / i << endl;
    }
}