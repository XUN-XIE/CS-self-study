//
//  main.cpp
//  16。5
//
//  Created by 谢逊 on 2020/1/22.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Report
{
private:
    string str;
public:
    Report(const string s) : str(s) { cout << "Object created.\n"; }
    
    ~Report() { cout << "Object deleted!\n"; }
    void comment() const { cout << str << "\n"; }
};

int main()
{
    {
    auto_ptr<Report> ps (new Report("using autpo_ptr"));
    ps->comment();
    }
    
    {
    shared_ptr<Report> ps (new Report("using shared_ptr"));
    ps->comment();
    }

    {
    unique_ptr<Report> ps (new Report("using unique_ptr"));
    ps->comment();
    }
    
    return 0;
}
