#include "INCLUDE.hpp"

int main()
{
    const string s = "Keep out!";

    for (auto &c: s)
    // the type of c is "const char &""
        c = "X";
    
    cout << s << endl;

    return 0;
}