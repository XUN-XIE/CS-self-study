#include "INCLUDE.hpp"

int main()
{
    list<int> list1= {1,2,3,4,5,6,7,8,9};
    deque<int> deq1;
    deque<int> deq2;

    auto list_iter = list1.cbegin();
    while(list_iter != list1.cend())
    {
        if (*list_iter % 2 == 0)
            deq1.push_back(*list_iter);
        else
            deq2.push_back(*list_iter);
        list_iter++;
    }
    print(deq1);
    print(deq2);
}