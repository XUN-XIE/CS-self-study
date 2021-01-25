#include "INCLUDE.hpp"

int main()
{
    deque<int> origin;
    for(int i = 1; i != 10; i++)
        origin.push_back(i);
    
    deque<int> insert;
    copy(origin.begin(), origin.end(), inserter(insert, insert.begin()));
    print(insert);

    deque<int> front;
    copy(origin.begin(), origin.end(), front_inserter(front));
    print(front);

    deque<int> back;
    copy(origin.begin(), origin.end(), back_inserter(back));
    print(back);
}