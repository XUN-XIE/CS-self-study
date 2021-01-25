//
//  main.cpp
//  exercise10.6
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "Move.hpp"

int main()
{
    Move first(10, 10);
    first.showmove();
    Move second(15, 15);
    second.showmove();
    
    Move third = first.add(second);
    third.showmove();
    
    first.reset();
    first.showmove();
}
