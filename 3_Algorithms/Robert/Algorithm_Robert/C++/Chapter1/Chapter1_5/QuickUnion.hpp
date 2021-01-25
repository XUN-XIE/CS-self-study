#include "UnionFind.hpp"

int UF::find(int p)
{
    while (p != id[p])
        p = id[p];
    return p;
}

void UF::union_together(int p, int q)
{
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) return;

    id[pRoot] = qRoot;

    count--;
}