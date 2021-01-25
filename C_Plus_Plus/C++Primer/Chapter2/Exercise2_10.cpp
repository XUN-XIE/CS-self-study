#include <string>
#include <iostream>

std::string global_str;
int global_int;

int display();

int main() {
    int local_int;
    std::string local_str;

    std::cout << global_str << std::endl << local_str << std::endl << global_int << std::endl << local_int << std::endl;

    display();

    return 0;
}

int display(){
    int iii;
    std::cout << iii;

    return iii;
}