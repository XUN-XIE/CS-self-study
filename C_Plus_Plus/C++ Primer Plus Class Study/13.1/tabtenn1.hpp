//
//  tabtenn1.hpp
//  13.1
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef tabtenn1_hpp
#define tabtenn1_hpp

#include "tabtenn0.hpp"

class Ratedplayer : public Tabletennisplayer
{
private:
    unsigned int rating;
public:
    Ratedplayer (unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    Ratedplayer (unsigned int r = 0, const Tabletennisplayer & tp);
    unsigned int Rating() const { return rating; }
    void ReserRating (unsigned int r) { rating = r; }
    
    
};

#endif /* tabtenn1_hpp */
