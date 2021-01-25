#ifndef INDEXMINPQ_HPP
#define INDEXMINPQ_HPP

// 实现还有问题，测试未通过
#include <bits/stdc++.h>
using namespace std;

template <typename Key>
class IndexMinPQ
{
private:
    int maxN;        // maximum number of elements on PQ
    int n;           // number of elements on PQ
    int * pq;        // binary heap using 1-based indexing
    int * qp;        // inverse of pq - qp[pq[i]] = pq[qp[i]] = i
    Key * keys;      // keys[i] = priority of i

    bool greater(int i, int j) {   return keys[pq[i]] > (keys[pq[j]]);  }

    void exch(int i, int j)
    {
        int swa = pq[i];
        pq[i] = pq[j];
        pq[j] = swa;
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }

    void swim(int k)
    {
        while (k > 1 && greater(k / 2, k))
        {
            exch(k, k/2);
            k = k / 2;
        }
    }

    void sink(int k)
    {
        while (2 * k <= n)
        {
            int j = 2 * k;
            if (j < n && greater(j, j + 1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }
public:
    IndexMinPQ(int maxn)
    {
        if (maxn < 0)   cerr << "Illegal maxmimum number\n";
        maxN = maxn;
        n = 0;
        keys = new Key[maxN+1];
        pq = new int[maxN+1];
        qp = new int[maxN+1];
        for (int i = 0; i <= maxN; i++)
            qp[i] = -1;
    }

    bool isEmpty()  {   return n == 0;  }

    bool contains(int i)    {   return qp[i] != -1; }

    int size()  {   return n;   }

    void insert(int i, Key key)
    {
        if (contains(i))    cerr << "index is already in the priority queue\n";
        n++;
        qp[i] = n;
        pq[i] = i;
        keys[i] = key;
        swim(n);
    }

    int minIndex()
    {
        if (n == 0) cerr << "Priority queue underflow";
        return pq[1];
    }

    Key minKey()
    {
        if (n == 0) cerr << "Priority queue underflow";
        return keys[pq[1]];
    }

    int delMin()
    {
        if (n == 0) cerr << "Priority queue underflow";
        int min = pq[1];
        exch(1, n--);
        sink(1);
        assert (min == pq[n+1]);
        qp[min] = -1;           // delete
        keys[min] = Key();      // to help with garbage collection( this is used for JAVA, but I need to change it in C++)
        pq[n+1] = -1;           // not needed
        return min;
    }

    Key keyof(int i)
    {
        if (!contains(i))    cerr << "index is not in the priority queue\n";
        else return keys[i];
    }

    void changeKey(int i, Key key)
    {
        if (!contains(i))   cerr << "index is not in the priority queue\n";
        keys[i] = key;
        swim(qp[i]);
        sink(qp[i]);
    }

    void change(int i, Key key) {   changeKey(i, key);  }

    void decreaseKey(int i, Key key)
    {
        if (!contains(i))   cerr << "index is not in the priority queue\n";
        if (keys[i] == (key))
            cerr << "Calling decreaseKey() with a key equal to the key in the priority queue";
        if (keys[i] < (key))
            cerr << "Calling decreaseKey() with a key strictly greater than the key in the priority queue";
        keys[i] = key;
        swim(qp[i]);
    }

    void increaseKey(int i, Key key)
    {
        if (!contains(i))   cerr << "index is not in the priority queue\n";
        if (keys[i] == (key))
            cerr << "Calling decreaseKey() with a key equal to the key in the priority queue";
        if (keys[i] > (key))
            cerr << "Calling decreaseKey() with a key strictly less than the key in the priority queue";
        keys[i] = key;
        sink(qp[i]);
    }

    void deleteIndex(int i)
    {
        if (!contains(i))   cerr << "index is not in the priority queue\n";
        int index = qp[i];
        exch(index, n--);
        swim(index);
        sink(index);
        keys[i] = Key();
        qp[i] = -1;
    }


};

#endif