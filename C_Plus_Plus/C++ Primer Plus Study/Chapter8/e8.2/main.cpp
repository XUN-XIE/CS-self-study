//
//  main.cpp
//  e8.2
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Candybar
{
    string branch;
    double weight;
    int hot;
};

void input(Candybar & stucture, string branch = "Millennium Munch", double weight = 2.85, int hot = 350);

void show(const Candybar & structure);

int main()
{
    Candybar example;
    input(example);
    show(example);
    
    return 0;
}

void input(Candybar & structure, string branch, double weight, int hot)
{
    structure.branch = branch;
    structure.weight = weight;
    structure.hot = hot;
}

void show(const Candybar & structure)
{
    cout << structure.branch << endl << structure.weight << endl << structure.hot << endl;
}
