#include <iostream>

int main()
{
    int val = 10;

    std::cout << "Start:" << std::endl;
    while (val >= 0) {
        std::cout << val << std::endl;
        val--;
    }

    return 0;
}