#include "INCLUDE.hpp"

int main()
{
    list<int> list1= {1,2,3};
    vector<int> vec1= {4,5,6};

    vector<double> vec2(vec1.begin(), vec1.end());
    print(vec2);

    vector<double> vec3(list1.begin(), list1.end());
    print(vec3);
}