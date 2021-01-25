//
//  main.cpp
//  e9.1
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "golf.hpp"

int main()
{
    golf g;
    string name = "xiexun";
    int hc = 10;
    int num;
    setgolf(g, name, hc);
    showgolf(g);
    
    num = setgolf(g);
    showgolf(g);
    
    handicap(g, 888);
    showgolf(g);
    
    return 0;
}
