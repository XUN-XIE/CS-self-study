#include "INCLUDE.hpp"

int main()
{
    string input;
    deque<string> deq;
    while(cin >> input)
        deq.push_back(input);
    
    auto deq_iter = deq.cbegin();
    while(deq_iter != deq.cend())
        cout << *deq_iter++ << endl;
}