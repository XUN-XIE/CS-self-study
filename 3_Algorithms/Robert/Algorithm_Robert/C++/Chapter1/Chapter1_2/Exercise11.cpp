#include "INCLUDE.hpp"

class SmartDate
{
public:
    SmartDate(int m, int d, int y) : m(m), d(d), y(y) { if (!check()) cerr << "The input date is invalid" << endl; }
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }


private:
    int m;
    int d;
    int y;

    bool check();
};

bool SmartDate::check()
{
    set<int> m_30 = {2,4,6,8,9,11};

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

int main(){
    int m, d, y;
    cin >> m >> d >> y;

    SmartDate date(m, d, y);

    printf("\033[0;1m %d\\%d\\%d\033[0m\n", date.month(), date.day(), date.year());
}