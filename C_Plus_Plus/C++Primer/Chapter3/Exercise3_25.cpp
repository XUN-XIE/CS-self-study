#include "INCLUDE.hpp"

int main()
{
    vector<int> grade(11,0);
    int num;

    while(cin >> num)
        *(grade.begin() + num / 10) += 1;
    
    print(grade);

    return 0;
}