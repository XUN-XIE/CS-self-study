#include "INCLUDE.hpp"

/*
int main()
{
    string final_str, temporary;

    while(cin >> temporary)
        final_str += temporary + " ";
    cout << final_str << endl;

    return 0;
}
*/

int main()
{
    string total;
    cin >> total;

    int count = total.size();
    while (count > 0)
    {
        if (count % 3 == 0)
        {
            string temporary = total + " ";
            for(int i = 0; i < count; i++)
                temporary[i] = total[i];
            temporary[count] = ' ';
            for(int i = count; i < total.size(); i++)
                temporary[i+1] = total[i];
            total = temporary;
        }
        count--;
    }
    cout << total << endl;

    return 0;
}
