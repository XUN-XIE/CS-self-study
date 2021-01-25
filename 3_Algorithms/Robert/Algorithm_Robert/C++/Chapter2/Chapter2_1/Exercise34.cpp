#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <string>

using namespace std;

class Timer
{
public:
    Timer() { start = clock(); }
    double elapsedTime(string name, int size) 
    { 
        long long now = clock(); 
        printf("\033[0;35m");
        cout << name << " size " << size << " :";
        printf("\033[0m");
        printf(" : \033[0;31m%f\033[0m", (double)(now - start) / CLOCKS_PER_SEC);
        cout << " seconds" << endl;
        return (double)(now - start) / CLOCKS_PER_SEC;
    }
private:
    long long start;
};


void SelectionSort(vector<int> & vec)
{
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
            if (vec[j] < vec[min])
                min = j;
        swap(vec[i], vec[min]);
    }
}


void InsertionSort(vector<int> & vec)
{
    int size = vec.size();
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0 && vec[j] < vec[j-1]; j--)
            swap(vec[j], vec[j-1]);
}

void ShellSort(vector<int> & vec)
{
    int size = vec.size();
    int h = 1;
    while (h < size / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < size; i++)
            for (int j = i; j >= h && vec[j] < vec[j-h]; j -= h)
                swap(vec[j], vec[j-h]);
        h = h / 3;
    }
}


double test_algorithm( void (*f)(vector<int> &), string name, vector<int> & vec)
{
    vector<int> vec2(vec);
    double time;

    Timer select;
    f(vec);
    time = select.elapsedTime(name, vec.size());

    sort(vec2.begin(), vec2.end());
    assert(vec2 == vec);
    
    return time;
}



int main()
{
    int size = 5E4;
    vector<int> ordered;
    vector<int> reversed;
    vector<int> samed;
    vector<int> twokeyed;

    for (int i = 0; i < size; i++)
    {
        ordered.push_back(i);
        reversed.push_back(size - 1 - i);
        samed.push_back(0);
        twokeyed.push_back(i % 2);
    }

    // ordered
    test_algorithm( SelectionSort, "ordered SelectionSort", ordered);
    test_algorithm( InsertionSort, "ordered InsertionSort", ordered);
    test_algorithm( ShellSort, "ordered ShellSort", ordered);

    cout << endl << endl;

    // reversed
    test_algorithm( SelectionSort, "reversed SelectionSort", reversed);
    test_algorithm( InsertionSort, "reversed InsertionSort", reversed);
    test_algorithm( ShellSort, "reversed ShellSort", reversed);

    cout << endl << endl;

    // samed
    test_algorithm( SelectionSort, "samed SelectionSort", samed);
    test_algorithm( InsertionSort, "samed InsertionSort", samed);
    test_algorithm( ShellSort, "samed ShellSort", samed);

    cout << endl << endl;

    // twokeyed
    test_algorithm( SelectionSort, "twokeyed SelectionSort", twokeyed);
    test_algorithm( InsertionSort, "twokeyed InsertionSort", twokeyed);
    test_algorithm( ShellSort, "twokeyed ShellSort", twokeyed);

    cout << endl << endl;

}