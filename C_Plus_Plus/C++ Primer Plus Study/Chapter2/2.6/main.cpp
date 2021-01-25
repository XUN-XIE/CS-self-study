//
//  main.cpp
//  2.6
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

int stonetolb(int);
int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stong = ";
    cout << pounds << " pounds." << endl;
    
    return 0;
}

int stonetolb(int sts)
{
    return 14 * sts;
}
