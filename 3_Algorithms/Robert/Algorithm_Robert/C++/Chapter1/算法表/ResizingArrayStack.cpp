#include "ResizingArrayStack.hpp"

int main()
{
    ResizingArrayStack<int> stk(1);
    for (int i = 0; i < 1E2; i++)
        stk.push(i);
    stk.print();
    for (int i = 0; i < 1E2; i++)
        cout << stk.pop() << endl;
}