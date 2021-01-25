#include "SymbolGraph.hpp"
#include "BreadthFirstPaths.hpp"

bool lessThanYears(string target, int bound)
{
    int right_par = target.length() - 1;
    int left_par = target.length() - 6;
    // cout << target[left_par] << endl;
    // cout << target[right_par] << endl;
    if (target[left_par] == '(' && target[right_par] == ')')
    {
        int years = stoi(target.substr(left_par + 1, 4));
        // cout << years << endl;
        if (2020 - years < bound)
            return true;
        else
            return false;
    }
    else
        return true;
}

// int main()
// {
//     string test = "xie (1997)";
//     int bound = 30;
//     cout << lessThanYears(test, bound) << endl;
// }

int main()
{
    // Exercise 22
    string filename = "movies.txt";
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

    int bound = 30;
    while (getline(cin, sink))
    {
        if (!lessThanYears(sink, bound))
            continue;
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
                    if (lessThanYears(sink, bound))
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