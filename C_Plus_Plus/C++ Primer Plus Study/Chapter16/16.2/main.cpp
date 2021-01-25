//
//  main.cpp
//  16.2
//
//  Created by 谢逊 on 2020/1/17.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
//#include <ofstream>
#include <fstream>
//#include <iofstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("temporary.txt");
    
    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count = 0;
    getline(fin, item, ':');
    while (fin)
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }
    cout << "Done\n";
    fin.close();
    
    return 0;
}
