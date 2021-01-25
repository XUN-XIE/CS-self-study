#ifndef BULK_QUOTE_HPP
#define BULK_QUOTE_HPP

#include "Quote.hpp"
// derived class inherits from Quote
class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &, double, size_t, double);
    // override the base version in order to implement the bulk purchase discount policy
    double net_price(size_t)    const   override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

// 子类需要调用父类的 constructor
Bulk_quote::Bulk_quote(const string & book, double p, size_t qty, double disc) 
: Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}   

#endif