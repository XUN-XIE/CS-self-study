#include "CC_BFS.hpp"

int main()
{
    Graph graph("../tinyG.txt");
    CC cc(graph);
    int count = cc.get_count();
    cout << count << " components\n";

    vector<vector<int > > components(count);
    int num_V = graph.getV();
    for (int i = 0; i < num_V; i++)
        components[cc.get_id(i)].push_back(i);
    for (int i = 0 ; i < count; i++)
    {
        for (int j = 0; j < components[i].size(); j++)
            cout << components[i][j] << " ";
        cout << endl;
    }

}