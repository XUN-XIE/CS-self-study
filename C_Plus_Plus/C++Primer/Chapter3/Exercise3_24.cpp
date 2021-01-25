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

    print_adjacent(vec);
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
    for(auto i = vec.begin(); i != vec.end() - 1;)
        cout << *i + *(++i) << " ";
    cout << endl;
}

void print_sequence(vector<int> vec)
{
    decltype(vec.size()) length = vec.size();

// C++ can automatically truncate the digit precision
    cout << "----" << endl;
    for(auto i = vec.begin(), j = vec.end() - 1; j - i >= 0;)
        cout << *(i++) + *(j--) << " ";
    cout << endl;
}