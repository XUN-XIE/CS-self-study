#include "../AllSort.hpp"

int count_Merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux, int count)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
        aux[k] = vec[k];
    
    int count_index = -1;
    for (int k = low; k <= high; k++)
    {
        if (i > mid)                {vec[k] = aux[j++]; if (count_index == -1) count += high - j + 1; count_index = 1; }
        else if (j > high)          {vec[k] = aux[i++]; if (count_index == -1) count += mid - i + 1; count_index = 1;  }
        else if (aux[j] < aux[i])   vec[k] = aux[j++];
        else                        vec[k] = aux[i++];
    }
    return count;
}

// recursive top-down mergesort
int count_MergeSort(vector<int> & vec, int low, int high, vector<int> & aux, int count)
{
    if (high <= low) return 0;
    int mid = low + (high - low) / 2;
    count += count_MergeSort(vec, low, mid, aux, count);
    count += count_MergeSort(vec, mid+1, high, aux, count);
    count += count_Merge(vec, low, mid, high, aux, count);
    return count;
}


int count_TD_MergeSort(vector<int> & vec) 
{
    int count = 0;
    vector<int> aux(vec.size());
    return count_MergeSort(vec, 0, vec.size()-1, aux, count);
}

int main()
{
    int size = 1E4;
    vector<int> vec = produce(size);
    double size_double = size;
    cout << count_TD_MergeSort(vec) / size_double << endl;
}