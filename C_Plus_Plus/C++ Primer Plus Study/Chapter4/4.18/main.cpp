//
//  main.cpp
//  4.18
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    double * p3 = new double [3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    
    cout << "p3[1] is " << p3[1] << ".\n";
    
    p3 = p3 + 1;
    cout << "Noew p3[0] is " << p3[0] << " and " <<  "p3[1] s " << p3[1] << ".\n";
    cout << p3[2] << endl;
    
    p3 = p3 - 1;
    cout << p3[2] << endl;
    delete [] p3;
    
    return 0;
}
