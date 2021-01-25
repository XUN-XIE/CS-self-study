#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <bits/stdc++.h>
using namespace std;

// Base class
class Quote
{
public:
    Quote() = default;
    Quote(const string & book, double sales_price) : bookNo(book), price(sales_price) { }
    string isbn()   const;
    // derived classes will overide and apply different discount algorithms
    virtual double net_price(size_t n)  const;
    virtual ~Quote() = default;     // dynamic binding for the destructor
private:
    string bookNo;
protected:
    double price = 0.0;
};
#endif