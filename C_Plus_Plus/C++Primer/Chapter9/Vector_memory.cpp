#include "INCLUDE.hpp"

int main()
{
    vector<int> vec = {1};

    cout << "capacity of vector is: " << vec.capacity() << endl;

    vec.reserve(100);

    cout << "capacity of vector is: " << vec.capacity() << endl;

    vec.shrink_to_fit();

    cout << "capacity of vector is: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++)
        vec.push_back(i);
    
    cout << "capacity of vector is: " << vec.capacity() << endl;

    vec.resize(28);

    cout << "capacity of vector is: " << vec.capacity() << endl;

}