// #include "../AllSort.hpp"

int main()
{
    int size = 1E6;
    test_algorithm(TD_MergeSort, "TD_Merge", size);
    test_algorithm(BU_MergeSort, "BU_Merge", size);
}


// 第一次写的版本，比改进版本慢很多。 原因就是每次Merge都创建了一个新的aux

// // 辅助函数，用于MergeSort完后，Merge数组中的左右两个已排序好的序列，合并成一个序列
// void Merge(vector<int> & vec, int low, int mid, int high )
// {
//     // Mention! Mention! Mention!!!
//     // 这个写法并不好，因为每次递归调用都创建了一次aux数组，导致运算量增大
//     // 最好写成 class 形式，让aux变成共享的！！！
//     vector<int> aux(high-low+1);
//     int i = low, j = mid + 1;
//     for (int k = low; k <= high; k++)
//         aux[k-low] = vec[k];
//     for (int k = low; k <= high; k++)
//     {
//         if (i > mid)                vec[k] = aux[j++ - low];
//         else if (j > high)          vec[k] = aux[i++ - low];
//         else if (aux[j - low] < aux[i - low])   vec[k] = aux[j++ - low];
//         else                        vec[k] = aux[i++ - low];
//     }
// }

// // recursive top-down mergesort
// void MergeSort(vector<int> & vec, int low, int high)
// {
//     if (high <= low) return;
//     int mid = low + (high - low) / 2;
//     MergeSort(vec, low, mid);
//     MergeSort(vec, mid+1, high);
//     Merge(vec, low, mid, high);
// }

// // recursive Bottom-up mergesort
// void MergeSort(vector<int> & vec)
// {
//     int size = vec.size();
//     // vector<int> aux(size);
//     for (int sz = 1; sz < size; sz *= 2)
//         for (int low = 0; low < size - sz; low += 2 * sz)
//             Merge( vec, low, low + sz - 1, min(low + 2 * sz - 1, size - 1) );
// }

// void TD_MergeSort(vector<int> & vec) {MergeSort(vec, 0, vec.size()-1);}
// void BU_MergeSort(vector<int> & vec) {MergeSort(vec);}