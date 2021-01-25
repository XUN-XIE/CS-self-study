//
//  tabtenn0.hpp
//  13.1
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef tabtenn0_hpp
#define tabtenn0_hpp

#include <string>
#include <iostream>
using namespace std;

class Tabletennisplayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    Tabletennisplayer (const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};


#endif /* tabtenn0_hpp */
