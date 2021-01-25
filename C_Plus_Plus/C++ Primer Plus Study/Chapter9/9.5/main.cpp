//
//  main.cpp
//  9.5
//
//  Created by 谢逊 on 2020/1/16.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "support.hpp"

int main()
{
    std::cout << "Global warming s " << warming << " degrees.\n";
    update(0.1);
    std::cout << "Global warming s " << warming << " degrees.\n";
    local();
    std::cout << "Global warming s " << warming << " degrees.\n";
    
    return 0;
}

