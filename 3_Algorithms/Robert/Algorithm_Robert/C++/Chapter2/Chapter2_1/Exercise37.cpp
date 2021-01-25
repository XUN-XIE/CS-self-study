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
    int size = 1E5;
    vector<int> partialed;


    for (int i = 0; i < size; i++)
        partialed.push_back(i);

    vector<int> partialed2(partialed);
    vector<int> partialed3(partialed);
    for (int i = 0.95 * size; i < size; i++)
        partialed[i] = rand() % size;
    
    for (int i = size - 10; i < size; i++)
        partialed2[i] = rand() % size;

    for (int i = 0; i < 0.05 * size; i++)
    {
        int index = rand() % size;
        partialed[index] = rand() % size;
    }

    vector<int> randomed(size);
    for (int i = 0; i < size; i++)
        randomed[i] = rand() % size;

    // 不测试 selection sort，因为就是平方，测试没用

    // size = 1E5 测试
    test_algorithm(InsertionSort, "Insertion partialed1", partialed);
    test_algorithm(InsertionSort, "Insertion partialed2", partialed2);
    test_algorithm(InsertionSort, "Insertion partialed3", partialed3);
    test_algorithm(InsertionSort, "Insertion randomed  ", randomed);

     // size = 1E7 测试
    // test_algorithm(ShellSort, "ShellSort partialed1", partialed);
    // test_algorithm(ShellSort, "ShellSort partialed2", partialed2);
    // test_algorithm(ShellSort, "ShellSort partialed3", partialed3);
    // test_algorithm(ShellSort, "ShellSort randomed  ", randomed);
}