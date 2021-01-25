//
//  main.cpp
//  13.1
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "tabtenn0.hpp"

int main()
{
    Tabletennisplayer player1 ("Chuck", "Blizzard", true);
    Tabletennisplayer player2 ("Tara", "Boomdea", false);
    
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    player2.Name();
    if (player2.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    return 0;
}
