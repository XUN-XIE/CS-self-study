#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP
#include "INCLUDE.hpp"

class Sales_data
{

public:
    Sales_data() = default;
    // const 和 reference for last two arguments must be together or without together (if you want to pass the literal values such as 0,1 or const value)
    Sales_data(const string & s, unsigned u, double r) : bookNo(s), units_sold(u), revenue(r) {}
explicit    Sales_data(const string & s) : bookNo(s) {}
explicit    Sales_data(istream & is) { is >> bookNo >> units_sold >> revenue; }

    string isbn() const { return bookNo; }
    Sales_data & combine (const Sales_data&);
    double avg_price() const;

    inline double avg_price() { return revenue / units_sold; }

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

friend    Sales_data add(const Sales_data &, const Sales_data &);
friend    ostream & print(ostream &, const Sales_data &);
friend    istream & read(istream &, Sales_data &);
};

#endif