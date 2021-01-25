#include "INCLUDE.hpp"

set<int> m_30 = {2,4,6,8,9,11};

class SmartDate
{
public:
    SmartDate(int m, int d, int y) : m(m), d(d), y(y) { if (!check()) cerr << "The input date is invalid" << endl; }
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
    int dayOfTheWeek();


private:
    int m;
    int d;
    int y;

    bool check();
};

bool SmartDate::check()
{
    if (d > 31 || m > 12)
        return false;
    if (d < 1 || m < 1 || y < 0)
        return false;
    
    // check month that contain 30 days
    if (m_30.find(m) != m_30.end() && m != 2)
        if (d == 31)
            return false;

    // check February
    if (m == 2)
    {
        if (y % 400 == 0)
        {
            if (d > 28)
                return false;
        } 
        else
        {
            if (y % 4){
                if (d > 28) {return false;}
            } 
            else
            {
                if (d > 29) {return false;}
            }
        }
    }
    
    return true;
}

int SmartDate::dayOfTheWeek()
{
    assert(y >= 2000);

    int start = 6;
    long long count_days = d - 1;

    int months = m - 1;
    while (months > 0)
    {
        if (m_30.find(months) != m_30.end())
            count_days +=  30;
        else
            count_days += 31;
        months--;
    }
    if (y % 4 == 0 && m > 2)
        count_days -= 2;
    else if (y % 4 != 0 && m > 2)
        count_days -= 3; 

    int years = y - 1;
    while ( years >= 2000)
    {
        if (years % 4 || years == 2000)
            count_days += 365;
        else
            count_days += 366;
        years--;
    }

    return (count_days + 6) % 7 + 1;

}   


int main(){
    int m, d, y;
    cin >> m >> d >> y;

    SmartDate date(m, d, y);

    cout << (365 + 6) % 7 + 1 << endl;

    printf("\033[0;31m %d\\%d\\%d\033[0m\n", date.month(), date.day(), date.year());
    cout << "this is " << date.dayOfTheWeek() << endl;
}