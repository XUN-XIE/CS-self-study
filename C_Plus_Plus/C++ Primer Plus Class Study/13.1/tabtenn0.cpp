//
//  tabtenn0.cpp
//  13.1
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "tabtenn0.hpp"

Tabletennisplayer::Tabletennisplayer (const string & fn, const string & ln, bool ht): firstname(fn), lastname(ln), hasTable(ht)
{
    
}

void Tabletennisplayer::Name() const
{
    cout << lastname << ", " << firstname;
}
