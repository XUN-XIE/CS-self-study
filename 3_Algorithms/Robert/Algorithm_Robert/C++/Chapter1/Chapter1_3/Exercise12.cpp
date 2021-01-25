#include "INCLUDE.hpp"

// stack in C++ do not provide iterator for it.
// so I cannot apply iterator to copy it.
// but in C++, can pass argument by copy value rather than pass by reference.
// So we implement the copy by copy object to argument.
// Of course, this maybe not efficient as that of JAVA
template<typename T>
stack<T> stack_copy(stack<T> origin);

// swap()
int main()
{
    stack<string> test1;
    test1.push("xie");
    stack<string> test2 = stack_copy(test1);

    cout << test1.top() << test2.top() << endl;
}

template<typename T>
stack<T> stack_copy(stack<T> origin)
{
    stack<T> result;
    while ( !origin.empty() ){
        result.push(origin.top());
        origin.pop();
    }

    return result;
}