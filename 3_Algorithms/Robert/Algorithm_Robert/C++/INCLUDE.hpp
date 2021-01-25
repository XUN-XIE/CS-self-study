#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>



#include <iostream>
#include <fstream>
#include <sstream>

#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using std::begin;
using std::end;

using namespace std;

// vector<string> read_data(ifstream & is);
vector<double> read_data(ifstream & is);
void print_to_file(ofstream & os, vector<double> & vec);
void print(vector<string> vec);
void print(vector<int> vec);
void print(vector<double> vec);
void print(deque<int> deq);
void print(forward_list<int> fl);



// vector<string> read_data(ifstream & is)
// {
//     vector<string> vec;
//     string str;
//     while(cin >> str)
//         vec.push_back(str);
    
//     return vec;
// }

vector<double> read_data(ifstream & is)
{
    istream_iterator<double> in_dou(is), eof;
    vector<double> vec(in_dou, eof);
    
    return vec;
}

void print_to_file(ofstream & os, vector<double> & vec)
{
    ostream_iterator<double> out_dou(os, "\n");
    copy(vec.begin(), vec.end(), out_dou);
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

void print(vector<double> vec)
{
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}


void print(deque<int> deq)
{
    auto iter = deq.cbegin();
    while(iter != deq.cend())
        cout << *iter++ << " ";
    cout << endl;
}

void print(forward_list<int> fl)
{
    auto iter = fl.cbegin();
    while(iter != fl.cend())
        cout << *iter++ << " ";
    cout << endl;
}

#endif