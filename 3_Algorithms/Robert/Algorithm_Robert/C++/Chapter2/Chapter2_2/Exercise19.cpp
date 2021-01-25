#include "../AllSort.hpp"

int inversion_InsertionSort(vector<int> & vec)
{
    int count = 0;
    int size = vec.size();
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && vec[j] < vec[j-1]; j--)
            {swap(vec[j], vec[j-1]); count++;}
    return count;
}

// 见官网答案
int inversion_Merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux)
{
    int inversions = 0;
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
        aux[k] = vec[k];
    for (int k = low; k <= high; k++)
    {
        if (i > mid)                vec[k] = aux[j++];
        else if (j > high)          vec[k] = aux[i++];
        
        // 最关键的一步，因为右面的array如果赋值在左面，则中间的所有元素都是逆序的
        else if (aux[j] < aux[i])   {vec[k] = aux[j++]; inversions += mid - i + 1;}
        else                        vec[k] = aux[i++];
    }
    return inversions;
}

// recursive top-down mergesort
int inversion_MergeSort(vector<int> & vec, int low, int high, vector<int> & aux)
{
    int inversions = 0;
    if (high <= low) return 0;
    int mid = low + (high - low) / 2;
    inversions += inversion_MergeSort(vec, low, mid, aux);
    inversions += inversion_MergeSort(vec, mid+1, high, aux);
    inversions += inversion_Merge(vec, low, mid, high, aux);
    return inversions;
}


int inversion_TD_MergeSort(vector<int> & vec) 
{
    vector<int> aux(vec.size());
    return inversion_MergeSort(vec, 0, vec.size()-1, aux);
}


int main()
{
    int size = 50;
    vector<int> vec = produce(size);
    vector<int> vec2(vec);
    print(vec);
    int count = inversion_InsertionSort(vec);
    cout << count << endl;

    int count2 = inversion_TD_MergeSort(vec2);
    cout << count2 << endl;
}
