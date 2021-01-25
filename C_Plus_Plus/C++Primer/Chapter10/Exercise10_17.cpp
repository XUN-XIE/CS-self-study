#include "INCLUDE.hpp"
#include "Sales_data.cpp"

int main()
{
    vector<Sales_data> vec;
    vec.push_back(Sales_data("0-0",1,1));
    vec.push_back(Sales_data("1-0",1,1));
    vec.push_back(Sales_data("0-1",1,1));
    vec.push_back(Sales_data("1-1",1,1));

    sort(vec.begin(), vec.end(), [] (const Sales_data & data1, const Sales_data & data2) { return data1.isbn() < data2.isbn(); } );

    auto iter = vec.cbegin();
    while (iter != vec.cend())
        cout << (iter++)->isbn() << "\t";
    cout << endl;
}

