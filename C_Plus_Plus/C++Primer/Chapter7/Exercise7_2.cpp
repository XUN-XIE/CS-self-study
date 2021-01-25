#include "INCLUDE.hpp"

struct Sales_data
{
    string isbn() const { return bookNo; }
    Sales_data & combine (const Sales_data&);
    double avg_price() const;


    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream & print(ostream &, const Sales_data &);
istream & read(istream &, Sales_data &);

Sales_data & Sales_data::combine (const Sales_data & another)
{
    if (bookNo != another.bookNo)
        cerr << "The another ISBN is different from the that of first book" << endl;
    
    units_sold += another.units_sold;
    revenue += another.revenue;

    return *this;
}

int main()
{
    Sales_data one, two;
    one.bookNo = two.bookNo = "0-0";
    one.units_sold = two.units_sold = 2;
    one.revenue = two.revenue = 3;
    one = one.combine(two);

    cout << one.units_sold << endl;
}