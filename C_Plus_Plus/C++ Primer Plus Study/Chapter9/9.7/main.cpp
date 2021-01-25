//
//  main.cpp
//  9.7
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
int tom = 3;
int dick = 30;
static int harry = 300;

void remote_access();

int main()
{
    using namespace std;
    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    
    remote_access();
    
    return 0;
}
