//
//  main.cpp
//  4.22
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;
char * getname(void);

int main()
{
    char * name;
    
    name = getname();
    cout << name << " at " << (int *) name << "\n";
    delete [] name;
    
    name = getname();
    cout << name << " at " << (int *) name << "\n";
    delete [] name;
            
    
    return 0;
}

char * getname()
{
    char temp[80];
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    
    return pn;
}
