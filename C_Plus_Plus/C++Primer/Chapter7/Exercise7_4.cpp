#include "Person.hpp"

int main()
{
    Person xiexun;
    xiexun.name = "xie xun";
    xiexun.address = "xie wa";

    cout << xiexun.get_name() << "'s address is " << xiexun.get_address() << endl;
}