#include "LCA.hpp"

int main()
{
    Digraph DG("../tinyDG.txt");
    LCA lca(DG);
    cout << lca.getLCA(7, 8) << endl;
}