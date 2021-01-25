//
//  main.cpp
//  2.3
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int main()
{
    using namespace std;
    
    int carrots;
    
    cout << "How many carrots do you have?" << endl;
    cin >> carrots;
    cout << "Here are tow more. ";
    
    carrots += 2;
    
    // the next line concatenates output
//    cout << "Now you have " << carrots << " carrots." << endl;
    cout
    << "Now you have "
    <<  carrots
    << " carrots."
    << endl;

    return 0;
}
