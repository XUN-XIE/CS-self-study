#include "INCLUDE.hpp"

struct data_type
{
    string name;
    double num1;
    double num2;
};

int main()
{
    string name;
    double num1, num2;
    string line;
    
    vector<data_type> all_data;
    while (getline(cin, line))
    {
        istringstream in_line(line);
        in_line >> name;
        in_line >> num1;
        in_line >> num2;
        data_type data = {name, num1, num2};
        all_data.push_back(data);
    }

    for (auto &d : all_data)
    {
        cout << d.name << "\t" << (d.num1 / d.num2) << endl;
    }

}