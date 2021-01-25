#include "INCLUDE.hpp"



class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate();
    static void rate(double);

private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();

    static constexpr int period = 30;
    double daily_tbl[period];
};

int main()
{

}

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double Account::interestRate = initRate();