#include <bits/stdc++.h>
using namespace std;

// LSD string sort
//
// 这时基础版本的 LSD，只适用于所有 length 相同的 string
// 并且需要 examine 所有的字符！
//
// 不适用情况：
// 1. string 长度不同
// 2. string 长度较大
static void LSDsort(vector<string> & stringVec, size_t length, size_t R )
{
    // third parameter R assume this is ASCII alphabet
    size_t N = stringVec.size();
    vector<string> aux(N);
    
    for (int d = length - 1; d >= 0; d--)
    {
        
        // Sort by key-indexed counting on dth char

        // Compute frequency counts. 
        vector<int> count(R+1);
        for (size_t i = 0; i < N; i++)
            count[ stringVec[ i ][ d ] + 1 ]++;

        // Transform counts to indices.
        for (size_t r = 0; r < R; r++)
            count[ r + 1 ] += count[ r ];

        // Distribute.
        for (size_t i = 0; i < N; i++)
            aux[ count[ stringVec[ i ][ d ] ]++ ] = std::move(stringVec[i]);

        // Copy back.
        for (size_t i = 0; i < N; i++)
            stringVec[ i ] = std::move(aux[ i ]);
    }
}

void LSDsort( vector<string> & stringVec, size_t R = 256 )
{
    LSDsort( stringVec, stringVec[0].length(), R );
}





// MSD string sort
//
// 1. Small substring 不能用 MSD sort。而应该用改良版本的 insertionSort 结合可以实现O(1)的substr操作的string 类解决该问题
// 2. Equal keys 不适合使用 MSD sort。因为 MSD sort 碰到 equal keys 会逐一对每个字母进行一遍递归调用，加大了开销！
// worst case of MSD sort 就来自于 all same string
// 即使有 大量的string具有相同的 prefix substring，也不适合使用 MSD sort
// 3. Extra space。 aux array 每次都需要创建，不过只有 size N 并且可以用一个总的 aux array，因此可以解决
// 问题的关键在于 count array! 并且 其size 为 R + 2，如果碰到大的 R，比如 unicode R = 65536 就会导致很大的空间开销！而且每次递归的调用 Sort 都要创建一个 count array！并且在递归下去的时候，上层的 Sort 中的 count array 还不会被销毁（因为没有跳出 scope）
//
// Performance：
// 1. random input：sublinear time
// 2. nonrandom input：sublinear time but need to examine more equal keys
// 3. worst case：all same string!
//
// Time performance: linear with R, N and W(string lenth)
// Space performance: linear with R times length of longest string (plus N)
//
// 因此，MSA不适合：
// 1. R 比较大（空间开销过大）
// 2. equal keys较多（递归层数过多）
class MSD
{
private:
    int R;   // radix
    int M;   // cutoff for small subarrays
    vector<string> aux;  // auxiliary array for distribution

    size_t charAt(string & s, int d)  { int res = ( d < s.size() ) ?  s[d] :  -1; return res;  }

    void Sort(vector<string> & a, int low, int high, int d)
    {
        // Sort from a[lo] to a[hi], starting at the dth character.
        if (high <= low + M)
        {
            InsertionSort(a, low, high, d);
            return;
        }

        // Compute frequency counts.
        vector<int> count(R+2);
        for (int i = low; i <= high; i++)
            count[ charAt(a[i], d) + 2 ]++;
        
        // Transform counts to indices.
        for (int r = 0; r < R+1; r++)
            count[ r+1 ] += count[ r ];
        
        // Distribute
        for (int i = low; i <= high; i++)
            // 不要理解复杂了，这里的 charAt 
            // 其实和 LSD 算法一样的，就是 a[i][d]
            // 只不过为了 处理 长度短于 d 的string
            // 才自己新创建的 charAt 函数
            aux[ count[ charAt(a[ i ], d) + 1 ]++ ] = std::move(a[ i ]);
        
        // copy back
        for (int i = low; i <= high; i++)
            a[ i ] = std::move(aux[ i - low]) ;

        // Recursively Sort for each character value.
        for (int r = 0; r < R; r++)
            Sort(a, low + count[ r ], low + count[ r+1 ] - 1, d + 1);
    }

    // 为了解决 MSD 在小substring 上空间开销过大的问题
    // 即使转换成 insertionSort，可以避免空间开销过大！
    void InsertionSort(vector<string> & a, int low, int high, int d)
    {
        // Sort from a[lo] to a[hi], starting at the dth character.
        for (int i = low; i <= high; i++)
            // ！！！！！！！！！！！！！！！！！！！！有一条限制，这个算法高效的要求是 substr 操作的时间复杂度为 O(1) ！！！！！！！！！！！！！！！！！！！！！！！！！！！！
            // 因此，如果想在C++使得这个算法高效，必须自己实现一个 string 类，达到 substr 时间复杂度为 constant 的要求
            for (int j = i; j > low && (a[ j ].substr(d) < a[ j-1 ].substr(d) ); j--)
                swap(a[j], a[j-1]);
    }

public:
    void Sort(vector<string> & a)
    {  
        int N = a.size();
        aux = vector<string>(N);
        Sort(a, 0, a.size() - 1, 0);
    }

    MSD(int r = 256, int m = 15) : R(r), M(m) { }
};







// Quick-3way string sort
// MSD 的改进版本
// 不需要额外的 空间 aux 存储数组
// 适合 equal keys
static int charAt(string & s, int d)    { int res = ( d < s.size() ) ?  s[d] :  -1; return res;  }
static void Quick3Sort(vector<string> & a, int low, int high, int d)
{
    if (high <= low) return;

    int lt = low, gt = high;

    // partition 
    int v = charAt(a[ low ], d);

    // cursor
    int i = low + 1;
    while (i <= gt)
    {
        // 左面都是小的，右面都是大的，按照 dth 排序
        int  t = charAt(a[ i ], d);
        // 如果比 partition 小，换到左面的 lt
        if      (t < v) swap(a[lt++], a[i++]);
        // 这里 比partition 大，但是不增加 i 的原因
        // 因为右面的 值 并没有 examine 过，所以交换后 不知道 新的 i 位置的值 相比于 partition 是大是小
        // 比 partition 小的，可以不用再次 examine，因为每次交换后的值，examine 过
        else if (t > v) swap(a[i], a[gt--]);
        else            i++;
    }

    // lt 记录的是 partition 的最小 index
    // 如果传进来的是 全相同的 string，这里 low > lt - 1因此调用直接返回，因为 调用的 high < low
    Quick3Sort(a, low, lt - 1, d);
    // Equal keys in dth sort
    // v >= 0 判断 目前的 d 没有超过 string 的长度
    if (v >= 0) Quick3Sort(a, lt, gt, d + 1);
    // gt 记录的是 partition 的最大 index
    Quick3Sort(a, gt+1, high, d);
}
void Quick3Sort(vector<string> & a)
{
    Quick3Sort(a, 0, a.size() - 1, 0);
}
