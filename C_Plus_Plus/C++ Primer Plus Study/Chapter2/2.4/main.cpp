//
//  main.cpp
//  2.4
//
//  Created by 谢逊 on 2020/1/11.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    
    double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    
    cin >> area;
    
    double side;
    side = sqrt(area);
    
    cout << "That's the equivalent of a square " << side
    << " feet to the side." << endl;
    
    cout << "How fascinating!" << endl;
    
    return 0;
}
