#include "INCLUDE.hpp"

bool longer_6(string & str);

int main()
{
    vector<string> vec = {"xie","xun","xiexun","ruiwan"};

    int count = count_if(vec.begin(), vec.end(), bind(longer_6, placeholders::_1));

    cout << count << endl;
}

bool longer_6(string & str)
{
    return str.size() >=6;
}