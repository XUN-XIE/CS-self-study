#include "KosarajuSCC.hpp"

int main()
{
    Digraph DG("tinyDG.txt");
    KosarajuSCC SCC(DG);
    cout << SCC.get_count() << " components" << endl;
}