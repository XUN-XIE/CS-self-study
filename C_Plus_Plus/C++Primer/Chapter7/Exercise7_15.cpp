#include "Person.cpp"

int main()
{
    Person xiexun("xie xun", "xie wa");
    print(cout, xiexun) << endl;

    Person wan(cin);
    print(cout, wan) << endl;
}