#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include <bits/stdc++.h>
using namespace std;

// 其实可以使用继承写这两个class。区别很小，只需要改sink, swim, del即可，但是我不会模版加继承的技术
template <typename T>
class MaxPQ
{
private:
    vector<T> pq;
    int N;
    int capacity;
    void resize() { vector<T> tmp(capacity*2); capacity *= 2; pq.swap(tmp); copy(tmp.begin(), tmp.end(), pq.begin()); }
    void shrink() { vector<T> tmp(capacity/2); capacity /= 2; pq.swap(tmp); copy(tmp.begin(), tmp.begin() + N + 1, pq.begin()); }

    void swim(int k)
    {
        while (k > 1 && pq[k/2] < pq[k])
        {
            swap(pq[k/2], pq[k]);
            k /= 2;
        }
    }

    void sink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            // 这个比较说明，向下走，只关心children里的大值。因为我们要满足father比children大
            if (j < N && pq[j] < pq[j+1]) j++;
            if (pq[k] >= pq[j]) break;
            swap(pq[k], pq[j]);
            k = j;
        }
    }

    // Exercise 15
    bool Ordered(int k)
    {
        if (k > N)  return true;
        // 比较孩子比比较父亲好调用一些，因为比较父亲，不好处理最大值
        // compare children;
        int left = 2 * k;
        int right = 2 * k + 1;
        if (left <= N && pq[left] > pq[k]) return false;
        if (right <= N && pq[right] > pq[k]) return false;
        return Ordered(left) && Ordered(right);
    }
public:
    MaxPQ(int maxN) { pq = vector<T>(maxN); N = 0; capacity = maxN; }
    bool isEmpty() { return N == 0; }
    int size() { return N; }

    void insert(T v)
    {
        // 因为总占用是N+1, index0 为空
        if (N == capacity - 1)
            resize();
        pq[++N] = v;
        swim(N);
    }

    T delMax()
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return pq[N--];
        T max = pq[1];
        swap(pq[1], pq[N--]);
        // pq.erase(pq.begin() + N + 1);
        sink(1);
        if (N < capacity / 2)
            shrink();
        return max;
    }

    void output()
    {
        if (N > 0)
        {
            cout << pq[1];
            for (int i = 2; i <= N; i++)
                cout << " " << pq[i];
            cout << endl;
        }
    }

    // Exercise 15
    bool isOrdered() { return Ordered(1); }

    // Exercise 19
    MaxPQ(vector<T> & vec)
    {
        N = vec.size();
        capacity = N + 1;
        pq = vector<T>(capacity);
        copy(vec.begin(), vec.end(), pq.begin() + 1);
        for (int i = N / 2; i >= 1; i--)
            sink(i);
    }

    // Exercise 27
    T min()
    {
        T min = pq[N];
        for (int i = N; i > N / 2; i--)
            if (pq[i] < min)
                min = pq[i];
        return min;
    }
};

template <typename T>
class MinPQ
{
private:
    vector<T> pq;
    int N;
    int capacity;
    void resize() 
    // { vector<T> tmp(capacity*2); capacity *= 2; copy(pq.begin(), pq.end(), tmp.begin()); pq = tmp;}
    { vector<T> tmp(capacity*2); capacity *= 2; pq.swap(tmp); copy(tmp.begin(), tmp.end(), pq.begin()); }
    void shrink() { vector<T> tmp(capacity/2); capacity /= 2; pq.swap(tmp); copy(tmp.begin(), tmp.begin() + N + 1, pq.begin()); }

    void swim(int k)
    {
        while (k > 1 && pq[k/2] > pq[k])
        {
            swap(pq[k/2], pq[k]);
            k /= 2;
        }
    }

    void sink(int k)
    {
        while (2 * k <= N)
        {
            int j = 2 * k;
            // 这个比较说明，向下走，只关心children里的大值。因为我们要满足father比children大
            if (j < N && pq[j] > pq[j+1]) j++;
            if (pq[k] <= pq[j]) break;
            swap(pq[k], pq[j]);
            k = j;
        }
    }

    // Exercise 15
    bool Ordered(int k)
    {
        if (k > N)  return true;
        // 比较孩子比比较父亲好调用一些，因为比较父亲，不好处理最大值
        // compare children;
        int left = 2 * k;
        int right = 2 * k + 1;
        if (left <= N && pq[left] > pq[k]) return false;
        if (right <= N && pq[right] > pq[k]) return false;
        return Ordered(left) && Ordered(right);
    }
public:
    MinPQ(int maxN) { pq = vector<T>(maxN); N = 0; capacity = maxN; }
    bool isEmpty() { return N == 0; }
    int size() { return N; }

    void insert(T v)
    {
        // 因为总占用是N+1, index0 为空
        if (N == capacity - 1)
            resize();
        pq[++N] = v;
        swim(N);
    }

    T delMin()
    {
        if (N == 0)
            return 0;
        if (N == 1)
            return pq[N--];
        T min = pq[1];
        swap(pq[1], pq[N--]);
        // pq.erase(pq.begin() + N + 1);
        sink(1);
        if (N < capacity / 2)
            shrink();
        return min;
    }

    void output()
    {
        if (N > 0)
        {
            cout << pq[1];
            for (int i = 2; i <= N; i++)
                cout << " " << pq[i];
            cout << endl;
        }
    }

    // Exercise 15
    bool isOrdered() { return Ordered(1); }

    // Exercise 19
    MinPQ(vector<T> & vec)
    {
        N = vec.size();
        capacity = N + 1;
        pq = vector<T>(capacity);
        copy(vec.begin(), vec.end(), pq.begin() + 1);
        for (int i = N / 2; i >= 1; i--)
            sink(i);
    }
};

#endif