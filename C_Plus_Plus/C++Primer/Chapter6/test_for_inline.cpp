#include "INCLUDE.hpp"
inline double sigmoid(double num) {return 1.0 / (1 + num);}


int main()
{
    cout << sigmoid(2) << endl;

    assert(3==2);
}
