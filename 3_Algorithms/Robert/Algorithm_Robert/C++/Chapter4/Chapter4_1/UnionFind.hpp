#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP
#include <bits/stdc++.h>
using namespace std;

class UF
{
private:
    int * id;
    int count;
    int N;

public:
    UF()    {   id = NULL; }

    UF(int n)
    {
        N = n;
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
    }

    UF(const UF & other)
    {
        count = other.count;
        N = other.N;

        for (int i = 0; i < N; i++)
            id[i] = other.id[i];
    }

    UF & operator=(const UF & other)
    {
        count = other.count;
        N = other.count;

        auto nep = new int[N];
        delete [] id;
        for (int i = 0; i < N; i++)
            nep[i] = other.id[i];
        id = nep;

        return *this;
    }

    ~UF()   {   delete []   id; }

    int get_count() {   return count;   }

    bool connected(int p, int q) {   return find(p) == find(q);  }

    int find(int p);

    void union_together(int p, int q);
};

#endif