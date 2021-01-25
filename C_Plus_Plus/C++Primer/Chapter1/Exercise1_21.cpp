#include <iostream>
#include "Sales_item.hpp"

int main() {
    std::cout << "Enter two books" << std::endl;
    Sales_item book1, book2;
    std::cin >> book1 >> book2;
    
    if (book1.isbn() == book2.isbn())
        std::cout << book1 + book2 << std::endl;
    else
        std::cout << "the ISBN of two books is different." << std::endl;
    
    return 0;
}
