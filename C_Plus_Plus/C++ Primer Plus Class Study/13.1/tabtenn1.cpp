//
//  tabtenn1.cpp
//  13.1
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "tabtenn1.hpp"

Ratedplayer::Ratedplayer (unsigned int r , const string & fn , const string & ln, bool ht) : Tabletennisplayer(fn, ln, ht)
{
    rating = r;
}

Ratedplayer::Ratedplayer (unsigned int r = 0, const Tabletennisplayer & tp) : Tabletennisplayer(tp), rating(r)
{
    
}
