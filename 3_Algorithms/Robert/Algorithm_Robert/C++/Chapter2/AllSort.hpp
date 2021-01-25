#include <bits/stdc++.h>
using namespace std;

//各个算法的时间复杂度不能一概而论。还是要像书中一样分开学习其 比较次数 和 交换次数 ！！！ 
// 因为实践应用中，并不是每次都是sort int， 比如存在比较花费很高的情况，比如sort的对象是string类型或者 一个大的class类型。
//这时候很明显的就应该在相同时间复杂度的算法中挑选比较次数尽可能少的算法！！！

// 排序算法汇总表
/*
    //                                 Compare                 Exchange            array access
    Unstable
    // Selection Sort                  N ^ 2 / 2               N

    Stable
    // Insertion Sort(average case)    N ^ 2 / 4               N ^ 2 / 4                               (N distinct keys)
    // Insertion Sort(worst   case)    N ^ 2 / 2               N ^ 2 / 2
    // Insertion Sort(best    case)    N - 1                   0
    // Binary_Insertion_Sort from Discrete Mathematics and its Application book
    // Binary_Insertion_Sort(average)  N * lg(N)               same as above
    // Binary_Insertion_Sort(worst)    N * lg(N)               same as above
    // Binary_Insertion_Sort(best)     N                       same as above
    //                 The number of exchanges used by insertion sort is equal to the number of inversions in the array, 
    //                 and the number of compares is at least equal to the number of inversions 
    //                 and at most equal to the number of inversions plus the array size minus 1.

    Unstable
    // Shell Sort      The number of compares used by shellsort with the increments 1, 4, 13, 40, 121, 364, . . . is bounded by a small multiple of N times the number of increments used.

    Stable
    // Merge Sort(Top-down)            [0.5 * N * lg(N), N * lg(N)]    no          [~, 6 * N * lg(N)]
    // Merge Sort(Bottom-up)           [0.5 * N * lg(N), N * lg(N)]    no          [~, 6 * N * lg(N)]

    Unstable
    // Quick Sort(average case)        2 * N * lg(N)                                                   (N distinct keys)
    // Quick Sort(worst   case)        N ^ 2 / 2
    // Quick Sort(3-way partition)     2 * ln2 * N * H                                                 (H is Shannon Entropy)

    Unstable
    // Heap Construction               [~, 2 * N]               [~, N] 
    // Heap Sort                       [~, 2 * N * lg(N) + 2 * N]
*/
// 排序算法汇总表
/*

    // Algorithm	stable	in place	order of growth to running time	            extra space	            notes

    // Selection	no	    yes		    N ^ 2                                       1	
    // Insertion	yes	    yes		    [N, N ^ 2]                                  1	                    depends on order of items
    // Shell	    no	    yes		    N * lg(N) OR N ^ (6 / 5)                    1	
    // Quick	    no	    yes			N * lg(N)                                   lg(N)                   probabilistic guarantee
    // 3-way Quick	no	    yes			[N, N * lg(N)]                              lg(N)                   probabilistic, also depends on distribution of input keys
    // Merge	    yes	    no		    N * lg(N)                                   N	
    // Heap	    no	    yes		    N * lg(N)                                   1	

*/
// 从开课吧看到的。InsertionSort, MergeSort都是稳定排序
// SelectionSort, QuickSort都是不稳定排序
// 稳定与否，取决于排序前后的元素相对位置是否改变

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 辅助函数
void print(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
class Timer
{
public:
    Timer() { start = clock(); }
    double elapsedTime(string name, int size) 
    { 
        long long now = clock(); 
        printf("\033[0;35m");
        cout << name << " size " << size << " :";
        printf("\033[0m");
        printf(" : \033[0;31m%f\033[0m", (double)(now - start) / CLOCKS_PER_SEC);
        cout << " seconds" << endl;
        return (double)(now - start) / CLOCKS_PER_SEC;
    }
private:
    long long start;
};
vector<int> produce(long long size, long long max = -1)
{
    srand(0);
    vector<int> vec(size);
    if (max > 0)
    {
        for (int i = 0; i < size; i++)
        vec[i] = rand() % max;
    }
    else
    {
        for (int i = 0; i < size; i++)
        vec[i] = rand();
    }
    
    return vec;
}
double test_algorithm( void (*f)(vector<int> &), string name, int size, bool print_or_not = false)
{
    vector<int> vec =  produce(size, 100);
    vector<int> vec2(vec);
    double time;

    Timer select;
    f(vec);
    time = select.elapsedTime(name, size);
    if (print_or_not) print(vec);
    sort(vec2.begin(), vec2.end());

    assert(vec2 == vec);
    
    return time;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter2_1 重点关注 InsertionSort 和 ShellSort
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionSort(vector<int> & vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
            if (vec[j] < vec[min])
                min = j;
        swap(vec[i], vec[min]);
    }
}
// InsertionSort 很有用，比如小序列时，它就是最快的。所以在高级算法，MergeSort和QuickSort里，最后的小序列都是用InsertionSort进行优化的
void InsertionSort(vector<int> & vec)
{
    int size = vec.size();
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && vec[j] < vec[j-1]; j--)
            swap(vec[j], vec[j-1]);
}
// ShellSort其实非常的快，在百万数据以内，甚至可以和 Nlog(N) 的算法进行抗衡！！！
void ShellSort(vector<int> & vec)
{
    int size = vec.size();
    int h = 1;
    while (h < size / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < size; i++)
            for (int j = i; j >= h && vec[j] < vec[j-h]; j -= h)
                swap(vec[j], vec[j-h]);
        h = h / 3;
    }
}
// Exercise 2.1.24
// 优化思想：sentinel优化，去掉内循环的一个判断条件
void InsertionSort_Sentinel(vector<int> & vec)
{
    int size = vec.size();
    
    // find minimum
    int min = 0;
    for (int i = 0; i < size; i++)
        if (vec[i] < vec[min])
            min = i;
    swap(vec[0], vec[min]);

    for (int i = 1; i < size; i++)
        for (int j = i; vec[j] < vec[j-1]; j--)
            swap(vec[j], vec[j-1]);
}
// Exercise 2.1.25
// 优化思想：不要每次都exchange，因为insertion sort里的元素是依次右移的
// 所以，swap反而增加了一倍的操作量！！！
// 因此对于需要连续移动的排序算法，可以用非swap优化
void InsertionSort_noex(vector<int> & vec)
{
    int size = vec.size();
    for (int i = 1; i < size; i++)
    {
        int tmp = vec[i];
        int j;
        for (j = i; j > 0 && vec[j-1] > tmp; j--)
            vec[j] = vec[j-1];
        vec[j] = tmp;
    }
}
void InsertionSort(vector<int> & vec, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
        for (int j = i; j > low && vec[j] < vec[j-1]; j--)
            swap(vec[j], vec[j-1]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter2_2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MergeSort 最主要的是学习它的  divide-and-conquer 思想
// 单次优化aux辅助存储array的MergeSort
// /*
// 辅助函数，用于MergeSort完后，Merge数组中的左右两个已排序好的序列，合并成一个序列
void Merge(vector<int> & vec, int low, int mid, int high, vector<int> & aux)
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
// */
// 经过书中三点优化后MergeSort。仅限于Top-down MergeSort
/*


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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter2_3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// QuickSort 也是 divide-and-conquer 思想的算法
// 最重要的部分，partition！！！！
int partition(vector<int> & vec, int low, int high)
{
    int i = low, j = high + 1;
    int v = vec[low];
    while (true)
    {
        while (vec[++i] < v) if (i == high) break;
        while (v < vec[--j]) if (j == low) break;
        if (i >= j) break;
        swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}
void QuickSort(vector<int> & vec, int low, int high)
{
    if (high <= low) return;
    int j = partition(vec, low, high);
    QuickSort(vec, low, j-1);
    QuickSort(vec, j+1, high);
}
void QuickSort(vector<int> & vec)
{
    // random_shuffle(vec.begin(), vec.end());
    QuickSort(vec, 0, vec.size() - 1);
}
// first improvement
void cutoff_Quicksort(vector<int> & vec, int low, int high)
{
    if (high - low < 15) {InsertionSort(vec); return;}
    int j = partition(vec, low, high);
    QuickSort(vec, low, j-1);
    QuickSort(vec, j+1, high);
}
// second improvement
int & median(int &i, int &j, int &k)
{
    return  ((i < j) ?
            ((j < k) ? j : (i < k) ? k : i) :
            ((k < j) ? j : (k < i) ? k : i));
}
int median_partition(vector<int> & vec, int low, int high)
{
    int i = low, j = high + 1;

    // 这里使用了 lvalue ，所以返回的还是vec里的对象
    swap(median(vec[low], vec[(low+high)/2], vec[high]), vec[low]);
    int v = vec[low];
    while (true)
    {
        while (vec[++i] < v) if (i == high) break;
        while (v < vec[--j]) if (j == low) break;
        if (i >= j) break;
        swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}
// third improvement, best one !!!
void Quick3way(vector<int> & vec, int low, int high)
{
    if (high - low < 15) {InsertionSort(vec, low, high); return;}
    swap(vec[low], median( vec[low], vec[(low+high)/2], vec[high] ) );
    if (high < low) return;
    int lt = low, i = low + 1, gt = high;
    int v = vec[low];
    while (i <= gt)
    {
        int cmp = vec[i] < v ? -1 : 1;
        if (vec[i] == v)
            cmp = 0;

        if (cmp < 0)        swap(vec[lt++], vec[i++]);
        else if (cmp > 0)   swap(vec[i], vec[gt--]);
        else                i++;
    }
    Quick3way(vec, low, lt - 1);
    Quick3way(vec, gt + 1, high);
}
void Quick3way(vector<int> & vec) {Quick3way(vec, 0, vec.size()-1);}
// this one is fast but slower than the Quick3way
// this is the best QuickSort provided from answer in website
// it containes the first and second improvement. Sentinels and Medians
int Fast_partition(vector<int> & vec, int low, int high)
{
    swap(vec[low], median( vec[low], vec[(low+high)/2], vec[high] ) );
    int i = low, j = high + 1;
    int v = vec[low];
    while (vec[++i] < v)
        if (i == high)
        {
            swap(vec[low], vec[high]);
            return high;
        }

    while (v < vec[--j])
        if (j == low + 1)
            return low;

    while (i < j)
    {
        swap(vec[i], vec[j]);
        while (vec[++i] < v);
        while (v < vec[--j]);
    }
    swap(vec[low], vec[j]);

    return j;
}
void Fast3way(vector<int> & vec, int low, int high)
{
    if (high - low < 15) {InsertionSort(vec, low, high); return;}
    if (low >= high) return;
    int j = Fast_partition(vec, low, high);
    Fast3way(vec, low, j - 1);
    Fast3way(vec, j + 1, high);
}
void Fast3way(vector<int> & vec)
{
    Fast3way(vec, 0, vec.size() - 1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter 2.4
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// HeapSort
// 辅助函数，用于构造heap和处理heap
void sink(vector<int> & vec, int k, int N)
{
    // 这个判定需要解释，是为了减少内部第一个if的判断的
    // 因为可能要对比两个children的大小，为了防止第二个children超出了界限
    // 所以直接令第一个children小于 N - 1， 给第二个children留了一个位置
    while (2 * k + 1 < N - 1)
    {
        int j = 2 * k + 1;
        // 这个比较说明，向下走，只关心children里的大值。因为我们要满足father比children大
        if (vec[j] < vec[j+1]) j++;
        if (vec[k] >= vec[j]) break;
        swap(vec[k], vec[j]);
        k = j;
    }
}
void Heapsort(vector<int> & vec)
{
    int N = vec.size();
    for (int k = N / 2; k >= 0; k--)
        sink(vec, k, N);
    while (N > 0)
    {
        swap(vec[0], vec[--N]);
        // 因为上一步 N 减少了 1，所以sink的时候，相当于把最大值排除在Heap的sink外了！！！
        sink(vec, 0, N);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Chapter2.5
// Select 算法，用于寻找序列中第k大或小的元素位置
// public static Comparable
//   select(Comparable[] a, int k)
//   {
// StdRandom.shuffle(a);
// int lo = 0, hi = a.length - 1; while (hi > lo)
// {
// int j = partition(a, lo, hi); if (j == k) return a[k]; else if (j > k) hi = j - 1; else if (j < k) lo = j + 1;
// }
//      return a[k];
//   }

// Exercise 6 递归版本，但是有问题
int select(vector<int> & vec, int k, int low, int high)
{
    if (high > low)     return vec[k];
    int j = partition(vec, low, high);
    if (j == k)         return vec[k];
    else if (j > k)     return select(vec, k, low, j - 1);
    else if (j < k)     return select(vec, k, j + 1, high);
    return -1;
}

int select(vector<int> & vec, int k)
{
    int low = 0, high = vec.size() - 1;
    while (high > low)
    {
        int j = partition(vec, low, high);
        if (j == k)         return vec[k];
        else if (j > k)     high = j - 1;
        else if (j < k)     low = j + 1;
    }
    return vec[k];

    // Exercise 6 递归版本，但是有问题
    // return select(vec, k, low, high);
}






// from book Discrete Mathematics and its application. Chapter 3 Exercise 44,49
// improvement: it can reduce the compare between the elements in vector
// which means it is an improvement when you are sort with the object that consume many efforts when comarison
int binary_search_pos(vector<int> & vec, int low, int high, int ele)
{
    int pos;
    int mid;
    if (ele < vec[low])
        return low;
    // 注意这里容易发生 segmentation fault
    if (ele > vec[high])
        return high + 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ele < vec[mid])
            high = mid - 1;
        else if (ele > vec[mid])
            low = mid + 1;

        // 处理找到的情况，移动pos到最右侧相同的元素
        else
        {
            pos = mid;
            while (vec[pos] == vec[pos+1])
                pos++;
            pos++;
            return pos;
        }
    }

    // 处理未找到的情况
    return low;
}
void binary_insertion_sort(vector<int> & vec)
{
    for(int i = 1; i < vec.size(); i++)
    {
        // 确保 best case时，可以达到 N compare
        if (vec[i] > vec[i-1])
            continue;
        int pos = binary_search_pos(vec, 0, i, vec[i]);
        // 省去了顺序对比 elements in vecor 的过程
        while (pos < i)
            swap(vec[pos++], vec[i]);
    }
}