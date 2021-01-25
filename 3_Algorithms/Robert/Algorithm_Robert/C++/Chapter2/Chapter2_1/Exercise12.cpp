#include <vector>
#include <iostream>

using namespace std;

vector<int> produce(int size, long long max = 10000)
{
    srand(0);
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
        vec[i] = rand() % max;
    return vec;
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
        {
            long long count = 0;
            for (int j = i; j >= h && vec[j] < vec[j-h]; j -= h)
            {
                swap(vec[j], vec[j-h]);
                count++;
                cout << "size is " << size << ". And the compare is " << count << ". the ratio is " << (double)count / size << endl;
            }
        }
        h = h / 3;
    }
}

int main()
{
    for (int i = 100; i < 1E4+1; i *= 10)
    {
        vector<int> vec = produce(i);
        ShellSort(vec);
        int size = vec.size();
        
    }
}