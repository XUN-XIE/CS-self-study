//
//  main.cpp
//  7.16
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

void countdown(int n);

int main()
{
    countdown(4);
    
    return 0;
}

void countdown(int n)
{
    using namespace std;
    
    cout << "Couting down ... " << n << endl;
    if (n > 0)
        countdown(n - 1);
    cout << n << ": Kamboom!\n";
}
