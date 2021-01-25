#include "INCLUDE.hpp"

bool Parentheses(string & str);

int main()
{
    string str1( "[()]{}{[()()]()}" );
    string str2( "[(]) ");

    cout << Parentheses(str1) << "\t" << Parentheses(str2) << endl;
}

vector<char> left_P = { '(', '[', '{' };
vector<char> right_P = { ')', ']', '}' };

bool Parentheses(string & str)
{
    stack<char> Pars;
    auto iter = str.cbegin();
    
    while(iter != str.cend())
    {
        if ( find(left_P.cbegin(), left_P.cend(), *iter) != left_P.cend() )
            Pars.push(*iter);
        else {
            auto iter_right_Word = find(right_P.cbegin(), right_P.cend(), *iter);
            char left_word = Pars.top();
            if (left_word != *( left_P.cbegin() + ( iter_right_Word - right_P.cbegin() ) )  )
                return false;
            else
                Pars.pop();
        }
        iter++;
    }

    return Pars.empty();
}