#include "INCLUDE.hpp"

int main()
{
    forward_list<int> fl= {1,2,3,4,5,6,7,8,9};
    auto curr = fl.begin();
    auto prev = fl.before_begin();

    while (curr != fl.cend())
    {
        if (*curr % 2 == 0)
        {
            prev = curr;
            curr++;
        }
        else
            curr = fl.erase_after(prev);
    }
    print(fl);
}