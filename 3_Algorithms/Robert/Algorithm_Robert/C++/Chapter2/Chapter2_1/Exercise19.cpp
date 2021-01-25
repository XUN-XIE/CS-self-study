#include <vector>
#include <iostream>

using namespace std;

long long ShellSort(vector<int> & vec)
{
    int size = vec.size();
    int h = 1;
    while (h < size / 3)
        h = 3 * h + 1;

    long long count = 0;
    while (h >= 1)
    {
        for (int i = h; i < size; i++)
        {
            for (int j = i; j >= h && vec[j] < vec[j-h]; j -= h)
            {
                swap(vec[j], vec[j-h]);
                count++;
            }
        }
        h = h / 3;
    }

    return count;
}

int main()
{
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < 100; i++)
    {
        vec1.push_back(i);
        vec2.push_back(99-i);
    }

    int count1, count2;
    count1 = ShellSort(vec1);
    count2 = ShellSort(vec2);

    cout << count1 << endl;
    cout << count2 << endl;

    vector<int> vec3 = vec2;
    for (int i = 1; i < 100; i++)
    {
        if (i % 4 == 0)
            vec3[i] += 100;
        if (i % 13 == 0)
            vec3[i] += 1000;
        if (i % 40 == 0)
            vec3[i] += 10000;
    }
    cout << ShellSort(vec3) << endl;
}