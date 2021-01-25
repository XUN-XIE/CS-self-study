//
//  Move.cpp
//  exercise10.6
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "Move.hpp"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

Move Move::add(const Move & m) const
{
    Move n;
    n.x = x + m.x;
    n.y = y + m.y;
    
    return n;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
