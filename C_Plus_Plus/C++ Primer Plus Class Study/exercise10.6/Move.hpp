//
//  Move.hpp
//  exercise10.6
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};

#endif /* Move_hpp */
