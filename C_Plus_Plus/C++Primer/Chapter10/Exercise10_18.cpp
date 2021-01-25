#include "INCLUDE.hpp"

string make_plural(size_t, const string &, const string &);
void bigges(vector<string> & words, vector<string>::size_type sz);
void elimDups(vector<string> &);



int main()
{
    vector<string> vec = {"xie", "xun", "xiewa", "wan", "rui", "wanrui"};

    bigges(vec, 4);
}



string make_plural(size_t ctr, const string & word, const string & ending)
{
    return (ctr > 1) ? word + ending : word;
}

void bigges(vector<string> & words, vector<string>::size_type sz)
{
    elimDups(words);
    // stable_sort( words.begin(), words.end(), 
    // [] (const string & a, const string & b) { return a.size() < b.size(); } );

    // auto wc = find_if( words.begin(), words.end(),
    // [sz] (const string & a) { return a.size() >= sz; } );
    auto wc = partition(words.begin(), words.end(), 
    [sz] (string & str) { return str.size() < sz; } );

    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;

    for_each(wc, words.end(),
    [] (const string & s) { cout << s << " "; } );

    cout << endl;
}

void elimDups(vector<string> & words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}