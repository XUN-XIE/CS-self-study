#include "INCLUDE.hpp"

int main()
{
    vector<int> test;

    Timer timer;
    for(int i = 0; i < 1E8; i++)
        test.push_back(i);
    double time_consumed = timer.elapsedTime();
    cout << time_consumed << endl;
}