#include "INCLUDE.hpp"

vector<int> read_int();
void print_adjacent(vector<int> vec);
void print_sequence(vector<int> vec);

int main()
{
    // vector<int> vec = read_int();

// /* 
//easy for test pupose
    vector<int> vec;
    for (int i = 0; i < 11; i++)
        vec.push_back(i);

// */
    print(vec);

    // print_adjacent(vec);
    print_sequence(vec);

    return 0;
}


vector<int> read_int()
{
    vector<int> vec;
    int i;
    while(cin >> i)
        vec.push_back(i);
    
    return vec;
}

void print_adjacent(vector<int> vec)
{
    for(int i = 0; i < vec.size()-1; i++)
        cout << vec[i] + vec[i+1] << " ";
    cout << endl;
}

void print_sequence(vector<int> vec)
{
    decltype(vec.size()) length = vec.size();

// C++ can automatically truncate the digit precision
    for(int i = 0; i < (length + 1) / 2; i++)
        cout << vec[i] + vec[length-1-i] << " ";
    cout << endl;
}