#include "../AllSort.hpp"

void BU_Merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
        aux[k] = vec[k];
    for (int k = low; k <= high; k++)
    {
        if (i > mid)                vec[k] = aux[j++];
        else if (j > high)          vec[k] = aux[i++];
        else if (aux[j] < aux[i])   vec[k] = aux[j++];
        else                        vec[k] = aux[i++];
    }
}

void BU_MergeSort(vector<int> & vec)
{
    int size = vec.size();
    vector<int> aux(vec.size());
    for (int sz = 1; sz < size; sz *= 2)
        for (int low = 0; low < size - sz; low += 2 * sz)
            BU_Merge( vec, low, low + sz - 1, min(low + 2 * sz - 1, size - 1), aux );
}

// size 不用固定，找到一个就merge，直到最后size相平
void natural_merge(vector<int> & vec)
{
    int size = vec.size();
    vector<int> aux(vec.size());
    // for (int sz = 1; sz < size; sz *= 2)
        // for (int low = 0; low < size - sz; low += 2 * sz)
    
    int low = 0, mid, high;
    while (true)
    {
        // find first
        if (low >= vec.size())
        {
            low = 0;
            continue;
        }
        mid = low;
        while (vec[mid + 1] >= vec[mid] && mid < vec.size())
            mid++;
        if (mid >= vec.size())
        {
            low = 0;
            continue;
        }
        high = mid + 1;
        if (high >= vec.size())
        {
            low = 0;
            continue;
        }
        while (vec[high+1] >= vec[high] && high < vec.size())
            high++;
        BU_Merge(vec, low, mid, high, aux);
        if (high - low >= vec.size() - 1)
            break;
        low = high + 1;
    }
}


int main()
{
    test_algorithm(natural_merge, "BU", 1E6);
    test_algorithm(TD_MergeSort, "TD", 1E6);
}