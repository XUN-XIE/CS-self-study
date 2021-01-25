#include "SymbolGraph.hpp"
#include "../DFS_BFS/BreadthFirstPaths.hpp"

// 运行时 需要输入
int main()
{
    // Exercise 22
    string filename = "../movies.txt";
    string sp = "/";
    SymbolGraph sg(filename, sp);
    Graph G = sg.get_graph();

    string source = "Oscar (1991)";
    if (!sg.contains(source))
    {
        cout << source << " not in database.";
        return 0;
    }

    int s = sg.index(source);
    BreadthFirstPaths bfs(G, s);

    string sink;

    // add a count to save the information
    while (getline(cin, sink))
    {
        if (sg.contains(sink))
        {
            int t = sg.index(sink);
            if (bfs.hasPathTo(t))
            {
                auto out = bfs.pathTo(t);

                // // Exercise 22
                // double count = 0;
                while (!out.empty())
                {
                    // // Exercise 22
                    // count += 0.5;
                    auto content = out.top(); out.pop();
                    cout << "\t" << sg.name(content) << endl;
                }

                // // Exercise 22
                // cout << "The Degree of Separation is " << count << endl;
            }
            else
                cout << "Not connected" << endl;
        }
        else
            cout << "Not in database." << endl;
    }
}