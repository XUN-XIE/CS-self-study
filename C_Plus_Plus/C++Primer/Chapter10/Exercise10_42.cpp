#include "INCLUDE.hpp"

void elimDups(list<string> & words);

int main()
{
    list<string> lis= { "xie", "xun", "xiexun", "xun", "xie"};
    elimDups(lis);
    copy(lis.begin(), lis.end(), ostream_iterator<string>(cout, "\n"));
}

void elimDups(list<string> & words)
{
    words.sort();
    words.unique();
}