//
//  main.cpp
//  11.16
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "stonewt.hpp"

void display(const Stonewt & st, int n);

int main()
{
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);
    
    cout <<"The celebrity weighted ";
    incognito.show_stn();
    cout << "The detective weighted ";
    wolfe.show_lbs();
    cout << "The President weighted ";
    taft.show_lbs();
    
    incognito = 276.8;
    taft = 325;
    cout << "After dinner, the celebrity weighted";
    incognito.show_stn();
    cout << "After dinner, the President weighted ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weiighted even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}
