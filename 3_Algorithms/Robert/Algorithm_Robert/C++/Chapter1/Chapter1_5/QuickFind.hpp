#include "UnionFind.hpp"

int UF::find(int p) {   return id[p];   }

void UF::union_together(int p, int q)
{
    int pID = find(p);
    int qID = find(q);

    if (pID == qID) return ;

    for (int i = 0; i < N; i++)
        if (id[i] == pID)
            id[i] = qID;
    count--;
}