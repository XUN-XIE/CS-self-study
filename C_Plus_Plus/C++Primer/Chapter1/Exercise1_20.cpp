#include <iostream>
#include "Sales_item.hpp"

int main() {
    std::cout << "Enter book" << std::endl;
    Sales_item tmp_item;
    while (std::cin >> tmp_item)
        std::cout << tmp_item << std::endl;
    
    return 0;
}
