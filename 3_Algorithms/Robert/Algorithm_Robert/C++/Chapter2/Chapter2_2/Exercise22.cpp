#include "../AllSort.hpp"


// 结果很低效，应该是辅助函数用的太多了，导致每次merge使用了大量的时间
void interval_merge(vector<int> & vec, int low, int mid1, int mid2, int high, vector<int> & aux)
{
    int i = low, j = mid2;
    for (int k = low; k <= high; k++)
        aux[k] = vec[k];
    for (int k = low; k <= high; k++)
    {
        // if (k > mid1 && k <= mid2)
        //     k = mid2;
        if (i > mid1)               vec[k] = aux[j++];
        else if (j > high)          vec[k] = aux[i++];
        else if (aux[j] < aux[i])   vec[k] = aux[j++];
        else                        vec[k] = aux[i++];
        if (k == mid1 && mid1 != mid2)
            k = mid2 - 1;
    }
}

int & compare_triple(int & i, int & j, int & z, vector<int> & aux)
{
    return   aux[ aux[i] <= aux[j] ? i : j ] <= aux[z] ?  (aux[i] <= aux[j] ? i : j) : z ;
}

void triple_Merge(vector<int> & vec, int low, int mid1, int mid2, int high, vector<int> & aux)
{
    int i = low, j = mid1 + 1, z = mid2 + 1;
    for (int k = low; k <= high; k++)
        aux[k] = vec[k];
    for (int k = low; k <= high; k++)
    {
        if (i > mid1)               
            interval_merge(vec, j, mid2, z, high, aux);
        else if (j > mid2)
            interval_merge(vec, i, mid1, z, high, aux);
        else if (z > high)
            interval_merge(vec, i, mid1, j, mid2, aux);
        else
            vec[k] = aux[compare_triple(i,j,z,aux)++];
    }
}


// recursive top-down mergesort
void triple_MergeSort(vector<int> & vec, int low, int high, vector<int> & aux)
{
    if(high - low < 15)
        {InsertionSort(vec);
        return;}
    if (high <= low) return;
    int mid1 = low + (high - low) / 3;
    int mid2 = low + 2 * (high - low) / 3;
    triple_MergeSort(vec, low, mid1, aux);
    triple_MergeSort(vec, mid1+1, mid2, aux);
    triple_MergeSort(vec, mid2+1, high, aux);
    triple_Merge(vec, low, mid1, mid2, high, aux);
}

void triple_TD_MergeSort(vector<int> & vec) 
{
    vector<int> aux(vec.size());
    triple_MergeSort(vec, 0, vec.size()-1, aux);
}

int main()
{
    int size = 1E6;
    vector<int> vec = produce(size);
    // print(vec);
    // triple_TD_MergeSort(vec);
    // print(vec);
    test_algorithm(triple_TD_MergeSort, "triple", size);
}

