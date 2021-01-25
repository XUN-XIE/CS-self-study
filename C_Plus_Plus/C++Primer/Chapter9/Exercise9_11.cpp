#include "INCLUDE.hpp"

int main()
{
    vector<int> test1;
    vector<int> test2(10);
    vector<int> test3(10, 1);
    vector<int> test4(test3.begin(), test3.begin()+5);
    vector<int> test5 = {1,2,3,4,5};
    vector<int> test6(test3);

    print(test1);
    cout << endl;
    print(test2);
    cout << endl;
    print(test3);
    cout << endl;
    print(test4);
    cout << endl;
    print(test5);
    cout << endl;
    print(test6);
    cout << endl;
    
}