// #include "../AllSort.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

// 辅助函数，用于MergeSort完后，Merge数组中的左右两个已排序好的序列，合并成一个序列
void Merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= mid; k++)
        aux[k] = vec[k];
    for (int k = mid + 1; k <= high; k++)
        aux[k] = vec[high - k + mid + 1];

    for (int k = low; k <= high; k++)
    {
        if (aux[j] < aux[i])   vec[k] = aux[j++];
        else                        vec[k] = aux[i++];
    }
}

// recursive top-down mergesort
void MergeSort(vector<int> & vec, int low, int high, vector<int> & aux)
{
    if (high <= low) return;
    int mid = low + (high - low) / 2;
    MergeSort(vec, low, mid, aux);
    MergeSort(vec, mid+1, high, aux);
    Merge(vec, low, mid, high, aux);
}

// recursive Bottom-up mergesort
void MergeSort(vector<int> & vec)
{
    int size = vec.size();
    vector<int> aux(vec.size());
    for (int sz = 1; sz < size; sz *= 2)
        for (int low = 0; low < size - sz; low += 2 * sz)
            Merge( vec, low, low + sz - 1, min(low + 2 * sz - 1, size - 1), aux );
}

void TD_MergeSort(vector<int> & vec) 
{
    vector<int> aux(vec.size());
    MergeSort(vec, 0, vec.size()-1, aux);
}
void BU_MergeSort(vector<int> & vec) {MergeSort(vec);}

int main()
{
    int size = 10;
    vector<int> vec;
    for (int i = 0; i < size; i++)
        vec.push_back(size - i);

    vector<int> vec2(vec);
    TD_MergeSort(vec);

    // print(vec);
}