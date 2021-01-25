#include "SymbolGraph.hpp"

// 运行时 需要输入
int main()
{
    string filename = "../movies.txt";
    string sp = "/";
    SymbolGraph sg(filename, sp);
    cout << "-----" << endl;
    Graph G = sg.get_graph();

    string search;
    while (getline(cin, search))
    {
        // cout << search << "!!!" << endl;
        auto adj_v = G.get_adj(sg.index(search));
        for (auto w = adj_v.begin(); w != adj_v.end(); w++)
            cout << "\t" + sg.name(*w) << endl;
    }
}