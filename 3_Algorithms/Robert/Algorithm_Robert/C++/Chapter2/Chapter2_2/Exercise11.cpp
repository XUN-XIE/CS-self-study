#include "../AllSort.hpp"

/*
void InsertionSort(vector<int> & vec, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
        for (int j = i; j > low && vec[j] < vec[j-1]; j--)
            swap(vec[j], vec[j-1]);
}

// 辅助函数，用于MergeSort完后，Merge数组中的左右两个已排序好的序列，合并成一个序列
void Merge(vector<int> & src, vector<int> & dst, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
    {
        if (i > mid)                dst[k] = src[j++];
        else if (j > high)          dst[k] = src[i++];
        else if (src[j] < src[i])   dst[k] = src[j++];
        else                        dst[k] = src[i++];
    }
}


// recursive top-down mergesort
void MergeSort(vector<int> & src, vector<int> & dst, int low, int high)
{
    if (high - low <= 15)
    {
    // first improvement by experiment, 10% improvement
        InsertionSort(dst, low, high);
        return ;
    }


    int mid = low + (high - low) / 2;
    MergeSort(dst, src, low, mid);
    MergeSort(dst, src, mid+1, high);


    // second improvement AND
    // third improvement
    // avoid duplicated copy
    if (src[mid] <= src[mid+1])
    {   
        // 特别强调第三点优化，因为为了减少aux的copy，所以交替存放sorted value，比较难理解
        // 可以看出，在递归进入到小array时，28-38行，src和dst两个数组交替存放值
        // 但是，在merge之前，却把src里的存放的值，都复制给了dst，因此实现了improvement


        // 其实个人理解这是系统内部优化，就是利用了内置的直接移动  比  单个循环赋值更快产生的improvement


        // System.arraycopy(src, lo, dst, lo, hi - lo + 1);
        // OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);
        auto src_begin = src.begin() + low;
        auto src_end = src.begin() + high + 1;
        auto dst_start = dst.begin() + low;
        copy(src_begin, src_end, dst_start);
        return;
    }
    
    Merge(src, dst, low, mid, high);
    
}



void TD_MergeSort(vector<int> & vec) 
{
    vector<int> aux(vec);
    MergeSort(aux, vec, 0, vec.size()-1);
}


*/

int main()
{
    test_algorithm(TD_MergeSort, "TD_MergeSort", 1E7);
}