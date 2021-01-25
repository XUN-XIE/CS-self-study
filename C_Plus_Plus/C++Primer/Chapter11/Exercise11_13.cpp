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
        // first version
        // pairs.push_back(make_pair(*str_iter++, *num_iter++));

        // second version
        // pairs.push_back(pair<string, int>(*str_iter++, *num_iter++));

        // third version
        pairs.push_back({*str_iter++, *num_iter++});
    }
    cout << pairs[1].first << endl;

    cout << pairs.size() << endl;
}