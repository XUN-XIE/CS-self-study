//
//  main.cpp
//  Chpater6
//
//  Created by 谢逊 on 2020/1/14.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

void add(int *a[5], int size);

int main()
{
    int num = 0;
    int **pc = new int *[5];
    
    for (int i = 0; i < 2; i++)
        pc[i] = new int[2];
    
    for (int i = 0; i < 5; i ++)
    {
        for (int j = 0; j < 2; j++)
//            *(*(pc+j)+i) = num++;
            pc[j][i] = num++;
    }
    
    for (int i = 0; i < 5; i ++)
    {
        for (int j = 0; j < 2; j++)
            cout << *(*(pc+j)+i) << endl;
    }
    
    add(pc, 2);
    
    cout << pc << endl;
    cout << pc + 2 << endl;
    cout << *(pc + 1) << endl;
    cout << *(pc + 1) + 3 << endl;
    cout << *(*(pc + 1) + 3) << endl;
}

void add(int *a[5], int size)
{
    for (int i = 0; i < size; i++)
        a[0][i] += 1;
    
//    return &a[0][0];
}
