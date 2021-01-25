#include "Stack.hpp"

int main()
{
    Stack<int> stk;
    for (int i = 0; i < 1E2; i++)
        stk.push(i);
    stk.print();
    for (int i = 0; i < 1E2; i++)
        cout << stk.pop() << endl;
}