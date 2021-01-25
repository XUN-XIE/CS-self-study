//
//  main.cpp
//  e7.3
//
//  Created by 谢逊 on 2020/1/15.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void print_s(box s);
void vol(box * s);
void use(box s);

int main()
{
    box s = {"xiexun", 2, 3, 4};
    
    use(s);
    
    return 0;
}

void print_s(box s)
{
    cout << s.maker << endl;
    cout << s.height << endl;
    cout << s.width << endl;
    cout << s.length << endl;
    cout << s.volume << endl;
}

void vol(box * s)
{
    s->volume = s->length * s->width * s->height;
}

void use(box s)
{
    vol(&s);
    print_s(s);
}
