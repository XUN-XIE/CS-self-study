#include "Degrees.hpp"

void print(vector<int> & vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    Digraph DG("../tinyDG.txt");
    Degrees degree(DG);

    cout << DG << endl;

    cout << degree.indegree(0) << endl << degree.outdegree(0) << endl;
    vector<int> source = degree.sources();
    vector<int> sink = degree.sink();
    print(source);
    print(sink);
    cout << degree.isMap() << endl;
}