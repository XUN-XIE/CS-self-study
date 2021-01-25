//
//  main.cpp
//  7.17
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
using namespace std;

const int Len = 66;
const int Divs = 6;

void subdivide(char * ar, int low, int high, int level);

int main()
{
    char ruler[Len];
    int ;
    for (int i = 0; i < Len - 2; i++)
        ruler[i] = ' ';
    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    
    cout << ruler << endl;
    for (int i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
        for (int j = 0; j < Len - 2; j++)
            ruler[j] = ' ';
    }
    
    return 0;
}

void subdivide(char * ar, int low, int high, int level)
{
    if (level == 0)
        return;
    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}
