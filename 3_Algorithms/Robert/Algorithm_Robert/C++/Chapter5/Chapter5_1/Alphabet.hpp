#ifndef ALPHABET_HPP
#define ALPHABET_HPP

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

class Alphabet
{
public:
    Alphabet( const string & s ) : alpha(s) { }

    char toChar( size_t index ) const 
    {   
        if (index > alpha.length() )
        {
            cerr << "Access out of bound" << endl;
            exit(1);
        }
        return alpha[index];    
        }

    size_t toIndex( const char c ) const  
    {   
        if ( !this->contains( c ) )
        {
            cerr << "Cannot convert from char to index, because of noncharacter" << endl;
            exit(1);
        }
        return alpha.find( string(1, c) );   
    }

    bool contains( const char c ) const   {   return alpha.find( string(1, c) ) != string::npos;  }

    size_t R()  const                 {   return alpha.length();    }

    size_t lgR()  const              {   return ceil( log( this->R() ) );    }

    vector<int>
    toIndices(const string & s)   const
    {
        int len = s.length();
        vector<int> res(len);
        for (int i = 0; i < len; i++)
        {
            res[i] = this->toIndex( s[i] );
        }
        return res;
    }

    string
    toChars( const vector<int> & indices )  const
    {
        int len = indices.size();
        string res(len, 'a');
        for (int i = 0; i < len; i++)
        {
            res[i] = this->toChar( indices[i] );
        }
        return res;
    }

private:
    string alpha;
};

#endif