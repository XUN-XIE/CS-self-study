#include "INCLUDE.hpp"
#include "Sales_data.cpp"

bool compareIsbn(const Sales_data &, const Sales_data &);

int main()
{
    multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)> bookStore;
    multiset<Sales_data, decltype(compareIsbn)*> bookStore2;

    pair<string, string> xiexun = {"xie", "xun"};
}

bool compareIsbn(const Sales_data & data1, const Sales_data & data2)
{
    return data1.isbn() < data2.isbn();
}