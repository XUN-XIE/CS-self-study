#include "INCLUDE.hpp"

void swap(int * num1, int * num2);

int main()
{
    int num1 = 2, num2 = 10;
    swap(&num1, &num2);
    cout << num1 << "\t" << num2 << endl;
    
    return 0;
}

void swap(int * num1, int * num2)
{
    int tmp = *num2;
    *num2 = *num1;
    *num1 = tmp;
}