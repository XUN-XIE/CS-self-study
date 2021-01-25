#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

using std::begin;
using std::end;

using std::ostream;
using std::istream;

vector<string> read_data();
void print(vector<string> vec);
void print(vector<int> vec);



vector<string> read_data()
{
    vector<string> vec;
    string str;
    while(cin >> str)
        vec.push_back(str);
    
    return vec;
}

void print(vector<string> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

void print(vector<int> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}

#endif