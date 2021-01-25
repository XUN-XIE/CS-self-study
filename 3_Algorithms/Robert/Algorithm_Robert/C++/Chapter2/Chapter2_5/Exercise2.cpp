#include "../AllSort.hpp"

// 失败原因之一：系统内置的排序，string是按照字母优先的，不是长度优先的！！！
bool isCompound(string str1, string str2, string compound)
{
    string combination = str1 + str2;
    string combination2 = str2 + str1;
    return combination == compound || combination2 == compound;
}

vector<string> FindCompound(vector<string> & vec)
{
    vector<string> result;

    vector<int> length;
    for (int i = 0; i < vec.size(); i++)
        length.push_back(vec[i].size());

    int max_length = *max_element(length.begin(), length.end());

    int i, j;
    for (i = 0; i < vec.size(); i++)
    {
        for (j = i + 1; j < vec.size(); j++)
        {
            if (length[i] + length[j] > max_length)
                break;
            for (int k = j + 1; k < vec.size(); k++)
                if (isCompound(vec[i], vec[j], vec[k]))
                    result.push_back(vec[k]);
        }
        if (length[i] + length[j] > max_length)
            break;
    }
    return result;}


int main()
{
    vector<string> vec;
    string word;
    while (cin >> word)
        vec.push_back(word);
    sort(vec.begin(), vec.end());
    vector<string> result = FindCompound(vec);
    
    cout << endl << "result is:\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    cout << endl;
}