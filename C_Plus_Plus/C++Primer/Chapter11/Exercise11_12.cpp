#include "INCLUDE.hpp"

int main()
{
    vector<string> str = {"xie", "xun", "xiexun","wan","rui"};
    vector<int> num = {1,2,3,4,5};

    vector<pair<string, int>> pairs;

    auto str_iter = str.begin();
    auto num_iter = num.begin();
    while( str_iter != str.end())
    {
        pairs.push_back(make_pair(*str_iter++, *num_iter++));
    }

    cout << pairs.size() << endl;
}