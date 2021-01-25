//
//  main.cpp
//  5
//
//  Created by 谢逊 on 2020/1/12.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string branch;
    double weight;
    int calorie;
    
};

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    
    cout << snack.branch << endl << snack.weight << endl << snack.calorie << endl;
    
    CandyBar vec[3];
    vec[0] = {"xie", 1.0, 200};
    vec[1] = {"xun", 2.0, 300};
    vec[2] = {"Tong", 3.0, 400};
    
    cout << vec[0].weight << vec[1].calorie << vec[2].branch;
}
