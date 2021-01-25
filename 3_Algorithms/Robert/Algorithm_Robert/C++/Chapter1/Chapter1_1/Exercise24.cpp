#include "INCLUDE.hpp"

long long gcd(long long, long long, int depth);

int main(int argc, char* argv[])
{   
    int depth = 0;
    long long p = stol(string(argv[1])), q = stol(string(argv[2]));
    cout << gcd(p, q, depth) << endl;
}

long long gcd(long long p, long long q, int depth)
{
    if (q == 0)
        return p;
    long long r = p % q;
    depth++;
    string indention(depth, '\t');
    cout << indention << q << "\t" << r << endl;
    return gcd(q,r);
}