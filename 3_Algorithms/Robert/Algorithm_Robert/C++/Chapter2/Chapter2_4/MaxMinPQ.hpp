#ifndef MAXMINPQ_HPP
#define MAXMINPQ_HPP
#include <bits/stdc++.h>
using namespace std;
// Exercise 29
// it cannot work correctly for delMax and delMin!!!
template <typename T>
class MaxMinPQ
{
private:
    vector<T> maxPQ;
    vector<T> minPQ;
    int N;
    int capacity;

    // 这里的resize 和 shrink 都有细微的改动，就是copy函数里，不到end了，因为这样可以删除delMax和delMin里删除的元素
    void resize() 
    { 
        vector<T> tmp(capacity*2); capacity *= 2; maxPQ.swap(tmp); copy(tmp.begin(), tmp.begin() + N + 1, maxPQ.begin());
        vector<T> tmp2(capacity*2); capacity *= 2; minPQ.swap(tmp2); copy(tmp2.begin(), tmp2.begin() + N + 1, minPQ.begin()); 
    }
    void shrink() 
    {
        vector<T> tmp(capacity/2); capacity /= 2; maxPQ.swap(tmp); copy(tmp.begin(), tmp.begin() + N + 1, maxPQ.begin());
        vector<T> tmp2(capacity/2); capacity /= 2; minPQ.swap(tmp2); copy(tmp2.begin(), tmp2.begin() + N + 1, minPQ.begin()); 
    }

    void Maxswim(int k)
    {
        while (k > 1 && maxPQ[k/2] < maxPQ[k])
        {
            swap(maxPQ[k/2], maxPQ[k]);
            k /= 2;
        }
    }

    void Maxsink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            // 这个比较说明，向下走，只关心children里的大值。因为我们要满足father比children大
            if (j < N && maxPQ[j] < maxPQ[j+1]) j++;
            if (maxPQ[k] >= maxPQ[j]) break;
            swap(maxPQ[k], maxPQ[j]);
            k = j;
        }
    }

    void Minswim(int k)
    {
        while (k > 1 && minPQ[k/2] > minPQ[k])
        {
            swap(minPQ[k/2], minPQ[k]);
            k /= 2;
        }
    }

    void Minsink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            // 这个比较说明，向下走，只关心children里的大值。因为我们要满足father比children大
            if (j < N && minPQ[j] > minPQ[j+1]) j++;
            if (minPQ[k] <= minPQ[j]) break;
            swap(minPQ[k], minPQ[j]);
            k = j;
        }
    }

    // // Exercise 15
    // bool Ordered(int k)
    // {
    //     if (k > N)  return true;
    //     // 比较孩子比比较父亲好调用一些，因为比较父亲，不好处理最大值
    //     // compare children;
    //     int left = 2 * k;
    //     int right = 2 * k + 1;
    //     if (left <= N && pq[left] > pq[k]) return false;
    //     if (right <= N && pq[right] > pq[k]) return false;
    //     return Ordered(left) && Ordered(right);
    // }
public:
    MaxMinPQ(int maxN) { maxPQ = vector<T>(maxN); minPQ = vector<T>(maxN); N = 0; capacity = maxN; }
    bool isEmpty() { return N == 0; }
    int size() { return N; }

    void insert(T v)
    {
        // 因为总占用是N+1, index0 为空
        if (N == capacity - 1)
            resize();
        
        N++;
        maxPQ[N] = v;
        Maxswim(N);
        minPQ[N] = v;
        Minswim(N);
    }

    T delMax()
    {
        T max = maxPQ[1];
        swap(maxPQ[1], maxPQ[N--]);

        // 这一步改为在resize和shrink里自动不复制这一项
        // maxPQ.erase(maxPQ.begin() + N + 1);
        Maxsink(1);

        if (N < capacity / 2)
            shrink();
        
        // same change to minPQ
        minPQ = maxPQ;
        for (int i = N / 2; i >= 1; i--)
            Minsink(i);

        return max;
    }

    T delMin()
    {
        T min = minPQ[1];
        swap(minPQ[1], minPQ[N--]);

        // 这一步改为在resize和shrink里自动不复制这一项
        // minPQ.erase(minPQ.begin() + N + 1);
        Minsink(1);

        // same change to maxPQ
        maxPQ = minPQ;
        for (int i = N / 2; i >= 1; i--)
            Maxsink(i);

        if (N < capacity / 2)
            shrink();
        return min;
    }

    void output(string MINMAX = "MAX")
    {
        if (N > 0)
        {   
            if (MINMAX == "MAX")
            {
                cout << maxPQ[1];
                for (int i = 2; i <= N; i++)
                    cout << " " << maxPQ[i];
                cout << endl;
            }
            else
            {
                cout << minPQ[1];
                for (int i = 2; i <= N; i++)
                    cout << " " << minPQ[i];
                cout << endl;
            }
        }
    }

    T min() {   return minPQ[1];    }
    T max() {   return maxPQ[1];    }

    // // Exercise 15
    // bool isOrdered() { return Ordered(1); }

    // // Exercise 19
    // MaxPQ(vector<T> & vec)
    // {
    //     N = vec.size();
    //     capacity = N + 1;
    //     pq = vector<T>(capacity);
    //     copy(vec.begin(), vec.end(), pq.begin() + 1);
    //     for (int i = N / 2; i >= 1; i--)
    //         sink(i);
    // }

    // // Exercise 27
    // T min()
    // {
    //     T min = pq[N];
    //     for (int i = N; i > N / 2; i--)
    //         if (pq[i] < min)
    //             min = pq[i];
    //     return min;
    // }
};

#endif