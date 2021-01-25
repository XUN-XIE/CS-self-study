#include "String.hpp"

int main()
{
    String s1();
    String s2("hello");

    String s3(s1);
    cout << s3 << endl;
    s3 = s2;

    cout << s3 << endl;
}