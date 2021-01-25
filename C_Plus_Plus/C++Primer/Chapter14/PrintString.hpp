#include <bits/stdc++.h>
using namespace std;

class PrintString
{
public:
    PrintString(ostream & o = cout, char c = ' ') : os(o), sep(c) { }
    void operator()(const string & s) const {   os << s << sep; }

private:
    ostream &os;    // stream on which to write
    char sep;       // character to print after each output

};