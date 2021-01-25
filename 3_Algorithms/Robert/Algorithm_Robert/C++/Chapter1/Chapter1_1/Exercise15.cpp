#include "INCLUDE.hpp"

vector<int> histogram(vector<int> & vec, int M);

int main()
{
    vector<int> vec = {1,4,23,75,34,21,6};
    int M = *max_element(vec.begin(), vec.end());
    vector<int> count = histogram(vec, M);

    print(count);
}

vector<int> histogram(vector<int> & vec, int M)
{
    vector<int> count_vec(M);
    auto iter = vec.begin();
    while (iter != vec.end())
    {
        int num = count(vec.begin(), vec.end(), *iter);
        count_vec[*iter] = num;
        iter++;
        
    }

    return count_vec;
}