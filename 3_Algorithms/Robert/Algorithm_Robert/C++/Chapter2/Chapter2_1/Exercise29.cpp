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
    long long size = 1E7;
    vector<int> vec = produce(size);
    vector<int> vec2(vec);


    vector<int> H_vec;
    int h = 0;
    int count = 0;
    while (h < size)
    {
        int nine = (9 * pow(4, count) - 9 * pow(2, count) + 1);
        // int four = (pow(4, four_count) - 3 * pow(2, four_count) + 1);
        h = nine;
        count++;
        H_vec.push_back(nine);
    }
    count = 2;
    h = 0;
    while (h < size)
    {
        // int nine = (9 * pow(4, nine_count) - 9 * pow(2, nine_count) + 1);
        int four = (pow(4, count) - 3 * pow(2, count) + 1);
        h = four;
        count++;
        H_vec.push_back(four);
    }
    sort(H_vec.begin(), H_vec.end());

    Timer time;
    ShellSort_Hvec(vec, H_vec);
    time.elapsedTime("Shell with H vector",size);

    sort(vec2.begin(), vec2.end());
    assert(vec == vec2);

    test_algorithm(ShellSort, "Shell              ", size);
}