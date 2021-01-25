#include "Alphabet.hpp"

int main( int argc, char *argv[], char *envp[] )
{
    string fromCommand(argv[1]);
    Alphabet test( fromCommand );
    int R = test.R();
    vector<int> count(R);

    ifstream infile;
    infile.open(argv[2]);
    string s;
    infile >> s;
    int N = s.length();

    for (int i = 0; i < N; i++)
        if (test.contains( s[i] ))
            count[ test.toIndex( s[ i ] ) ]++;
    
    for (int c = 0; c < R; c++)
        cout << test.toChar( c ) << " " << count[ c ] << endl;
}