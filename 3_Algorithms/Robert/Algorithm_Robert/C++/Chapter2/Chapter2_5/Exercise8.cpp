#include "../AllSort.hpp"

vector<pair<string, int> > Frequency(vector<string> & vec)
{
    sort(vec.begin(), vec.end());
    vector<pair<string, int> > result;
    pair<string, int> tmp;
    tmp.first = vec[0];
    tmp.second = 1;
    result.push_back(tmp);
    for(int i = 1; i < vec.size(); i++)
    {
        int notfound = true;
        for (int j = 0; j < result.size(); j++)
            if (result[j].first == vec[i])
            {
                result[j].second += 1;
                notfound = false;
                break;    
            }
        if (notfound)
        {
            tmp.first = vec[i];
            tmp.second = 1;
            result.push_back(tmp);
        }
    }
    return result;
}

int main()
{
    vector<string> vec = {"xie", "xun", "xiexun", "xie", "xun"};
    vector<pair<string, int> > result = Frequency(vec);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << "\t" << result[i].second << endl;
    }
}