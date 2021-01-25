#include "../AllSort.hpp"

int main()
{
    vector<double> Se;
    vector<double> In;
    vector<double> Sh;
    vector<int> SIZE;
    for (int size = 128; size < 128 * pow(2,8) + 1; size *= 2)
    {
        double SeTime = test_algorithm(SelectionSort, "Selection", size);
        double InTime = test_algorithm(InsertionSort, "Insertion", size);
        double ShTime = test_algorithm(ShellSort,     "Shell    ", size);
        Se.push_back(SeTime);
        In.push_back(InTime);
        Sh.push_back(ShTime);
        SIZE.push_back(size);
    }

    cout << "Selection ratio \t Insertion ratio \t Shell ratio \t" << endl; 
    for (int i = 0; i < SIZE.size() - 1; i++)
    {
        cout << Se[i+1] / Se[i] << "\t\t\t";
        cout << In[i+1] / In[i] << "\t\t\t";
        cout << Sh[i+1] / Sh[i] << "\t\t\t\n";
    }
}