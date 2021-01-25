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



int main()
{
    Sales_data one, two;
    read(cin, one);
    read(cin, two);
    // one = one.combine(two);
    // one = add(one, two);

    print(cout, one) << endl;
    
}



Sales_data & Sales_data::combine (const Sales_data & another)
{
    if (bookNo != another.bookNo)
        cerr << "The another ISBN is different from the that of first book" << endl;
    
    units_sold += another.units_sold;
    revenue += another.revenue;

    return *this;
}

istream & read(istream & is, Sales_data & target)
{
    is >> target.bookNo >> target.units_sold >> target.revenue;
    return is;
}


ostream & print(ostream & os, const Sales_data & target)
{
    os << target.bookNo << "\t" << target.units_sold << "\t" << target.revenue;
    return os;
}


Sales_data add(const Sales_data & data1, const Sales_data & data2)
{
    // connot apply "combine" because the const for two data
    // so we can only construct a new object to store the summation.
    // We can only read not write two data
    Sales_data sum;
    if (data1.bookNo != data2.bookNo)
        cerr << "The another ISBN is different from the that of first book" << endl;
    
    sum.bookNo = data1.bookNo;
    sum.units_sold = data1.units_sold + data2.units_sold;
    sum.revenue = data1.revenue + data2.revenue;

    return sum;
}