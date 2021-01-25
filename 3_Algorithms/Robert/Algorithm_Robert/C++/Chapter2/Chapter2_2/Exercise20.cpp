#include "../AllSort.hpp"

// 见答案，两个关键点
void indirect_merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux, vector<int> & index)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
        aux[k] = index[k];
    for (int k = low; k <= high; k++)
    {
        if (i > mid)                index[k] = aux[j++];
        else if (j > high)          index[k] = aux[i++];
        // 关键步骤 2
        else if (vec[aux[j]] < vec[aux[i]])   index[k] = aux[j++];
        else                        index[k] = aux[i++];
    }
}

// recursive top-down mergesort
void indirect_mergesort(vector<int> & vec, int low, int high, vector<int> & aux, vector<int> & index)
{    
    if (high <= low) return;
    int mid = low + (high - low) / 2;
    indirect_mergesort(vec, low, mid, aux, index);
    indirect_mergesort(vec, mid+1, high, aux, index);
    indirect_merge(vec, low, mid, high, aux, index);
}

vector<int> indirect_TD(vector<int> & vec)
{
    vector<int> index(vec.size());

    // 关键步骤 1
    for (int i = 0; i < vec.size(); i++)
        index[i] = i;
    vector<int> aux(vec.size());
    indirect_mergesort(vec, 0, vec.size()-1, aux, index);

    return index;
}

int main()
{
    int size = 5;
    vector<int> vec = produce(size);
    print(vec);
    vector<int> index = indirect_TD(vec);
    
    print(index);
}