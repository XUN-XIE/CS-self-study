# include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";

    // there is a miss of right double comma
    std::cout << /* "*/" */;

    // nested commments pair
    std::cout << /* "*/" /* "/*" */;

    return 0;
}

