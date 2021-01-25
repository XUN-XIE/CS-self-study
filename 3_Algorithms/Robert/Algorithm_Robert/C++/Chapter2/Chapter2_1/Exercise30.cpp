#include "../AllSort.hpp"


// Exercise 2.1.29
void ShellSort_Hvec(vector<int> & vec, vector<int> H_vec)
{
    int size = vec.size();

    int last_index = H_vec.size() - 1;
    for (int h_index = last_index; h_index >= 0; h_index--)
    {
        int h = H_vec[h_index];

        for (int i = h; i < size; i++)
            for (int j = i; j >= h && vec[j] < vec[j-h]; j -= h)
                swap(vec[j], vec[j-h]);
    }
}

int main()
{
    long long size = 1E6;
    
    // vector<int> vec2(vec);


    int min_t = 0;
    double min_time = 100;
    for (int t = 2; t < 20; t++)
    {
        vector<int> vec = produce(size);
        vector<int> H_vec;
        int count = 0;
        while (pow(t, count) < size)
        {
            H_vec.push_back( pow(t,count) );
            count++;
        }

        Timer time;
        ShellSort_Hvec(vec, H_vec);
        double tmp_time = time.elapsedTime("Shell with H vector",size);
        if (tmp_time < min_time)
        {
            min_t = t;
            min_time = tmp_time;
        }
    }

    cout << min_t << "\t\t" << min_time << endl;
    // sort(vec2.begin(), vec2.end());
    // assert(vec == vec2);

    test_algorithm(ShellSort, "Shell              ", size);
}