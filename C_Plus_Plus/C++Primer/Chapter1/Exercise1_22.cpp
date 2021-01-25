#include <iostream>
#include "Sales_item.hpp"

int main() {
    std::cout << "Enter two books" << std::endl;
    Sales_item sum_book, book;
    std::cin >> sum_book >> book;
    
    while (sum_book.isbn() == book.isbn()) {
        sum_book += book;
        std::cin >> book;
    }

    std::cout << sum_book << std::endl;
    
    return 0;
}
