#include "INCLUDE.hpp"

int main()
{
    vector<string> vec = {"xie","xun","xiexun","ruiwan"};

    int count = count_if(vec.begin(), vec.end(), 
    [] (string & str) { return str.size() >= 6; } );

    cout << count << endl;
}