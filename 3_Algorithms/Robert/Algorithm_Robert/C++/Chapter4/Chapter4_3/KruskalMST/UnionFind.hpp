#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP
#include <bits/stdc++.h>
using namespace std;

// method union together remained to be finished
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

    ~UF()   {   delete []   id; }
    int get_count() {   return count;   }

    bool connected(int p, int q) {   return find(p) == find(q);  }

    int find(int p);

    void union_together(int p, int q);
};

#endif