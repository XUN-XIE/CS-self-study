#include "INCLUDE.hpp"

int main()
{
    vector<int> VI(10,42);
    vector<int> V0 {42,42,42,42,42,42,42,42,42,42};
    vector<int> VR;
    for (int i = 0; i < 10; i++)
        VR.push_back(42);

    print(VI);
    print(V0);
    print(VR);

    return 0;
}