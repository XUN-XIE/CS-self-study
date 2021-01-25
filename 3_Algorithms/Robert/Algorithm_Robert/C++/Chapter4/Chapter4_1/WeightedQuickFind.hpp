#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP
#include <bits/stdc++.h>
using namespace std;

class UF
{
private:
    int * id;
    int count;
    int * sz;
    int N;

public:
    UF()    {   id = NULL; sz = NULL;   }

    UF(int n)
    {
        N = n;
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    UF(const UF & other)
    {
        count = other.count;
        N = other.N;

        for (int i = 0; i < N; i++)
        {
            id[i] = other.id[i];
            sz[i] = other.sz[i];
        }
    }

    UF & operator=(const UF & other)
    {
        count = other.count;
        N = other.count;

        auto nep = new int[N];
        delete [] id;
        auto nep2 = new int[N];
        delete [] sz;
        for (int i = 0; i < N; i++)
        {
            nep[i] = other.id[i];
            npp2[i] = other.sz[i];
        }
        id = nep;
        sz = nep2;

        return *this;
    }

    ~UF()   {   delete []   id; }
    int get_count() {   return count;   }

    bool connected(int p, int q) {   return find(p) == find(q);  }

    // Weited quick find with path compression
    int find(int p)
    {
        int start = p;
        while (start != id[start]) 
            start = id[start];
        int root = start;
        while (p != id[p])
        {
            int tmp = p;
            p = id[p];
            id[tmp] = root;
        }
        return root;
    }

    void union_together(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (i == j) 
            return;
        
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }
};

#endif