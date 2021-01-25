//
//  main.cpp
//  6.16
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int SIZE = 60;

int main()
{
    char filename[SIZE];
    ifstream infile;
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    infile.open(filename);
    
    if (!infile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    
    double value;
    double sum = 0.0;
    int count = 0;
    
    infile >> value;
    while (infile.good())
    {
        ++count;
        sum += value;
        infile >> value;
    }
    
    if (infile.eof())
        cout << "End of file reached.\n";
    else if (infile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated by uniknow reason.\n";
        
    if (count == 0)
        cout << "No data processed.\n";
    else
        cout << "Items read: "<< count << endl << "Sum: " << sum << endl << "Average: " << sum / count << endl;
    
    infile.close();
    
    return 0;
}
