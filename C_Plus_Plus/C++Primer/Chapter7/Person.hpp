#ifndef PERSON_HPP
#define PERSON_HPP

#include "INCLUDE.hpp"

class Person
{
    string name;
    string address;

public:
    Person() = default;
    Person(const string & n, const string & a) : name(n), address(a) {}
    Person(istream & is) { is >> name >> address; }

    string get_name() const { return name; }
    string get_address() const { return address; }

friend    istream & read(istream &, Person &);
friend    ostream & print(ostream &, const Person &);
};

istream & read(istream &, Person &);
ostream & print(ostream &, const Person &);
#endif