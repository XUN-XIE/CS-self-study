//
//  main.cpp
//  14.20
//
//  Created by 谢逊 on 2020/1/21.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "tempmemb.hpp"

int main()
{
    beta<double> guy(3.5, 3);
    cout << "T was set to double\n";
    guy.Show();
    cout << "V was set to T, which s double, then V was set to int\n";
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";
    cout << "Done\n";
    
    return 0;
}
