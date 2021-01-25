#include "INCLUDE.hpp"

istream & read(istream &);

int main()
{
    read(cin);
}

istream & read(istream & is)
{
    int num;
    auto old_state = is.rdstate();
    while (is >> num)
    {cout << num << "\n";}

    is.setstate(old_state);

    return is;
}