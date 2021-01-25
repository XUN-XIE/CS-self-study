//
//  brass.hpp
//  13.7
//
//  Created by 谢逊 on 2020/1/19.
//  Copyright © 2020 谢逊. All rights reserved.
//

#ifndef brass_hpp
#define brass_hpp

#include <string>
#include <iostream>
using namespace std;
class Brass
{
private:
    string fullname;
    long acctnum;
    double balance;
public:
    Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void Viewacct() const;
    virtual ~Brass() {}
};

class Brassplus : public Brass
{
private:
    double maxloan;
    double rate;
    double owesbank;
public:
    Brassplus(const string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r =0.11125);
    Brassplus(const Brass & ba, double ml = 500, double r = 0.11125);
    
    virtual void Vewacct() const;
    virtual void Withdraw(double amt);
    void Resetmax(double m) { maxloan = m; }
    void Resetrate(double r) { rate = r; }
    void Resetowes() { owesbank = 0; }
};

#endif /* brass_hpp */
