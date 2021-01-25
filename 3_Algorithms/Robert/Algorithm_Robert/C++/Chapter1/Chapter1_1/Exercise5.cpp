#include "INCLUDE.hpp"

int main(int argc, char **argv)
{
    double x = stod(string(argv[1])), y = stod(string(argv[2]));
    if (x >= 0 && x <= 1 && y >= 0 && y <= 1)
        cout << true << endl;
    else
        cout << false << endl;
}