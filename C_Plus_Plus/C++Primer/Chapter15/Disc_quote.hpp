#include "Quote.hpp"

class Disc_quote: public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string & book, double price, size_t qty, double disc)
    : Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(size_t)    const = 0;
private:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string & book, double price, size_t qty, double disc)
    : Disc_quote(book, price, qty, disc) { }

    double net_price(size_t) const override;
};