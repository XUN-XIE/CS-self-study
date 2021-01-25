#include "INCLUDE.hpp"

class Employee
{
public:
    Employee() { ID_ALL++; name = ""; }
    Employee(const string & na) { name = na; ID_ALL++; }

    static int ID_ALL;
    string name;
};

int Employee::ID_ALL = 0;

int main()
{
    Employee a("A"), b("A"), c("A");
    Employee * A = &a;
    Employee * B = &b;
    Employee * C = &c;
    cout << Employee::ID_ALL << " " << Employee::ID_ALL << " " << Employee::ID_ALL << endl;
    cout << A->ID_ALL << B->ID_ALL << C->ID_ALL << endl;
}