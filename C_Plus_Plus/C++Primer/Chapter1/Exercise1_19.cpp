# include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int val1 = 0, val2 = 0, sum = 0;
    std::cin >> val1 >> val2;
    
    int tmp = val1;
    if (val1 < val2) {
        while (val2 >= tmp) {
            sum += tmp;
            tmp++;
        }
    }
    else {
        while (val2 <= tmp) {
            sum += tmp;
            tmp--;
        }
    }

    std::cout << "Sum of " << val1 << " to " << val2 << " inclusive is " << sum << std::endl;
    
    return 0;
}
