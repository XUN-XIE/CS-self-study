#include "INCLUDE.hpp"

// 思路
// 遇到右括号，向左取出表达式，直到遇到乘号，除号，然后加上左括号，再存入Stack
// 在回退时，左右括号抵消，为0后遇到high level operator加左括号
string complete_from_right(string & str);

int main()
{
    string expression( "1 + 2 ) * 3 - 4 ) * 5 - 6 ) )" );

    string result = complete_from_right(expression);

    cout << result << endl;

    return 0;
}

vector<string> high_level_symbol = {"*", "/"};

string complete_from_right(string & str)
{
    stack<string> expressions;

    stack<string> temporary_stack;

    stringstream read_word(str);
    string word;

    while (read_word >> word)
    {
        if (word != ")")
            expressions.push(word);
        else
        {
            expressions.push(")");
            int count_high_level = 0;
            while ( (!expressions.empty()) )
            {
                string top_word = expressions.top();
                auto iter = find( high_level_symbol.cbegin(), high_level_symbol.cend(), top_word );
                if ( iter != high_level_symbol.cend() ){
                    count_high_level++;
                    if ( count_high_level == 0)
                        break;
                }


                if ( top_word == ")")
                    count_high_level--;

                temporary_stack.push( top_word );
                expressions.pop();
            }
            
            temporary_stack.push("(");

            while ( !temporary_stack.empty() )
            {
                expressions.push( temporary_stack.top() );
                temporary_stack.pop();
            }
        }
    }

    string result;
    while ( !expressions.empty() )
    {
        result = expressions.top() + " " +result;
        expressions.pop();
    }

    return result;
}