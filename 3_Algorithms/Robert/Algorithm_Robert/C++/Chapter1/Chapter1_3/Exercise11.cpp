#include "INCLUDE.hpp"

double EvaluatePostfix(string & str);

int main()
{
    string expression = "3 4 + 5 *";
    double result = EvaluatePostfix(expression);


    cout << result << endl;
    assert(result == 35);
}

vector<string> symbols = {"*", "/", "+", "-"};

double EvaluatePostfix(string & str)
{
    stack<string> result;

    stringstream read_word(str);
    string word;

    while (read_word >> word)
    {
        auto iter = find(symbols.cbegin(), symbols.cend(), word);
        if (iter != symbols.cend()) {
            double operand2 = stod(result.top());
            result.pop();
            double operand1 = stod(result.top());
            result.pop();

            if (word == "+") result.push(to_string(operand1 + operand2));
            else if (word == "-") result.push(to_string(operand1 - operand2));
            else if (word == "*") result.push(to_string(operand1 * operand2));
            else if (word == "/") result.push(to_string(operand1 / operand2));
        }
        else 
            result.push(word);
    }

    return stod(result.top());
}