// #include "QuickFind.hpp"
// #include "QuickUnion.hpp"
#include "WeightedQuickFind.hpp"

int main()
{
    int N;
    ifstream infile;

    // 不要用除了WeightedQuickFind算法跑 largeUF.txt，太慢了
    infile.open("largeUF.txt");
    infile >> N;
    UF uf(N);
    int val;
    int p, q;
    int count = 0;

    double start = clock();
    while (infile >> val)
    {
        if (count % 2 == 0)
            p = val;
        else
        {
            q = val;
            uf.union_together(p, q);
        }
        count++;
    }
    cout << uf.get_count() << endl;
    double end = clock();
    cout << (end - start) / CLOCKS_PER_SEC << endl;
}