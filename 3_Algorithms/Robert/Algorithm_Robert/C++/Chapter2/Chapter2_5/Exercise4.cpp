#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> dedup(vector<string> & vec)
{
    sort(vec.begin(), vec.end());
    vector<string> result;
    for(int i = 0; i < vec.size() - 1; i++)
        if (vec[i] != vec[i+1])
            result.push_back(vec[i]);
    result.push_back(vec[vec.size() - 1]);
    
    return result;
}

int main()
{
    vector<string> vec = {"xie", "xun", "xiexun", "xie", "xun"};
    vector<string> result = dedup(vec);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}