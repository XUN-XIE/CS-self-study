#include "SymbolGraph.hpp"
#include "BreadthFirstPaths.hpp"
// int main()
// {
//     string filename = "movies.txt";
//     string sp = "/";
//     SymbolGraph sg(filename, sp);
//     Graph G = sg.get_graph();

//     string source = "Oscar (1991)";
//     if (!sg.contains(source))
//     {
//         cout << source << " not in database.";
//         return 0;
//     }

//     int s = sg.index(source);
//     BreadthFirstPaths bfs(G, s);

//     vector<vector<string > > vec(11);
//     for (int i = 0; i < sg.get_graph().getV(); i++)
//     {
//         string sink = sg.name(i);
//         if (sg.contains(sink))
//         {
//             int t = sg.index(sink);
//             if (bfs.hasPathTo(t))
//             {
//                 auto out = bfs.pathTo(t);

//                 // // Exercise 22
//                 double count = 0;
//                 while (!out.empty())
//                 {
//                     // // Exercise 22
//                     count += 0.5;
//                     auto content = out.top(); out.pop();
//                     // cout << "\t" << sg.name(content) << endl;
//                 }
//                 if (((int)count * 2) % 2 == 0 && count < 10)
//                     vec[count].push_back(sink);
//             }
//             else
//                 // cout << "Not connected" << endl;
//                 vec[10].push_back(sink);
//         }
//         else
//             cout << "Not in database." << endl;
//     }

//     cout << sg.get_graph().getV() << endl;
//     int index;
//     cin >> index;
//     cout << vec[index].size() << endl;
//     // for (int i = 0; i < vec[index].size(); i++)
//     //     cout << vec[index][i] << endl;
// }


// 答案， 只需要调用 BFS distTo 就可以，自己的解答把string还储存起来了，花费时间和存储空间了
int main()
{
    string filename  = "movies.txt";
    string delimiter = "/";
    string source    = "Oscar (1991)";

    SymbolGraph sg(filename, delimiter);
    Graph G = sg.get_graph();
    if (!sg.contains(source)) {
        cout << source << " not in database." << endl;
        return 0;
    }

    // run breadth-first search from s
    int s = sg.index(source);
    BreadthFirstPaths bfs(G, s);


    // compute histogram of Kevin Bacon numbers - 100 for infinity
    int MAX_BACON = 100;
    vector<int> hist(MAX_BACON + 1);
    for (int v = 0; v < G.getV(); v++) {
        int bacon = MAX_BACON < bfs.distTo(v) ? MAX_BACON : bfs.distTo(v);
        hist[bacon]++;

        // to print actors and movies with large bacon numbers
        if (bacon/2 >= 7 && bacon < MAX_BACON)
        {
            printf("%d ", bacon/2);
            cout << sg.name(v) << endl;
        }
    }

    // print out histogram - even indices are actors
    for (int i = 0; i < MAX_BACON; i += 2) {
        if (hist[i] == 0) break;
        printf("%3d %8d\n", i/2, hist[i]);
    }
    printf("Inf %8d\n", hist[MAX_BACON]);
}
