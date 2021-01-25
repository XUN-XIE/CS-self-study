#include "Person.hpp"

istream & read(istream & is, Person & target)
{
    is >> target.name >> target.address;
    return is;
}


ostream & print(ostream & os, const Person & target)
{
    os << target.name << "'s address is " << target.address;
    return os;
}