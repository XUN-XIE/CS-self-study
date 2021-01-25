#include "INCLUDE.hpp"

int main()
{
    list<int> target_list = { 0,1,2,3,4,5,6,5,4,3,2,1,0};
    auto iter = find(target_list.rbegin(), target_list.rend(), 0);

    cout << (   iter == (  target_list.rbegin()  )  ) << endl;
}