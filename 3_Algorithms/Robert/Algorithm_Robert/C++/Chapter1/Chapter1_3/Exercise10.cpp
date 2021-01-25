#include "INCLUDE.hpp"

string InfixToPostfix(string & str);

int main()
{
    string expression = "( ( 3 + 4 ) * 5 )";
    string result = InfixToPostfix(expression);


    cout << result << endl;
    assert(result == "3 4 + 5 * ");
}

vector<string> symbols = {"*", "/", "+", "-"};

string InfixToPostfix(string & str)
{
    stack<string> opers;

    stringstream read_word(str);
    string word;

    string result;

    while (read_word >> word)
    {
        auto iter = find(symbols.cbegin(), symbols.cend(), word);
        if (iter != symbols.cend())
            opers.push(word);
        else if (word == ")") {
            result += opers.top() + " ";
            opers.pop();
        }
        else if (word == "(") {}
        else
            result += word + " ";
    }
    return result;
}