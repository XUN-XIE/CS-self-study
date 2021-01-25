#include <iostream>

int main()
{
    int val1 = 0, val2 = 0, sum = 0;
    std::cout << "Enter two numbers(the first number must be less than the second number because I have not learn the usage of if-else syntax)" << std::endl;
    std::cin >> val1 >> val2;

    int tmp = val1;
    while (val2 >= tmp) {
        sum += tmp;
        tmp++;
    }

    std::cout << "Sum of " << val1 << " to " << val2 << " inclusive is " << sum << std::endl;

    return 0;
}