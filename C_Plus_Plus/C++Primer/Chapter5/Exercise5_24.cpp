#include "INCLUDE.hpp"

int main()
{
    int num1, num2;

    cin >> num1 >> num2;

    try
    {
        double result = num1 / num2;
        cout << result << endl;
    }
    catch(std::runtime_error err)
    {
        std::cout << "Your denomitor is zero!" << endl;
        std::cerr << err.what() << '\n';
    }
    
    return 0;
}