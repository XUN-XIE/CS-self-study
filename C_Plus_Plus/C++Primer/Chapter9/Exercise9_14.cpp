#include "INCLUDE.hpp"

int main()
{
    char a[] = {'1','2','3'};
    char b[] = {'x','i','e'};
    char c[] = {'w','a'};
    list<char *> C_style = {a, b, c};

    vector<string> modern;
    modern.assign(C_style.cbegin(), C_style.cend());

    print(modern);
}