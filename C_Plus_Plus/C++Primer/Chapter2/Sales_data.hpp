#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP
#include <string>

struct Sales_data
{
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif