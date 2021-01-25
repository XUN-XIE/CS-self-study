#include "../AllSort.hpp"

class Version
{
public:
    int first;
    int second;
    int third;

    Version() { first = second = third = 0; }
    Version(int f, int s, int t)
    {
        first = f;
        second = s;
        third = t;
    }

    bool operator<(Version & other)
    {
        if (this->first < other.first)
            return true;
        else if (this->first == other.first)
        {
            if (this->second < other.second)
                return true;
            else if (this->second == other.second)
            {
                if (this->third < other.third)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }

    bool operator>(Version & other)
    {
        if (this->first > other.first)
            return true;
        else if (this->first == other.first)
        {
            if (this->second > other.second)
                return true;
            else if (this->second == other.second)
            {
                if (this->third > other.third)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }

    bool operator==(Version & other)    {   return first == other.first && second == other.second && third == other.third;  }
};

