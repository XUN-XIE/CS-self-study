//
//  main.cpp
//  12.1
//
//  Created by 谢逊 on 2020/1/18.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include "stringbad.hpp"

void callme1(Stringbad &);
void callme2(Stringbad);

int main()
{
    {
        cout << "Starting an inner block.\n";
        Stringbad headline1("Celery Stalks at Midnight");
        Stringbad headline2("Lettuce Prey");
        Stringbad sports("Spanach leaves Bowl for Dollars");
        cout << "headline1 " << headline1 << endl;
        cout << "headline2 " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        
        cout << "Initialize one object to another:\n";
        Stringbad sailor = sports;
        cout << "salor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        Stringbad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exitng the block.\n";
    }
    cout << "End of main()\n";
    
    return 0;
}

void callme1(Stringbad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(Stringbad sb)
{
    cout << "String passe by value:\n";
    cout << "    \"" << sb << "\"\n";
}
