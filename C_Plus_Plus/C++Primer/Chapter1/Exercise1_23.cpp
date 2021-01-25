#include <iostream>
#include <vector>
#include "Sales_item.hpp"

using std::vector;

int main() {
    std::cout << "Enter book" << std::endl;
    Sales_item tmp_item;
    vector<Sales_item> all_books {tmp_item};
    vector<Sales_item> kinds_books {tmp_item};
    vector<int> number {1};
    while (std::cin >> tmp_item)
        all_books.push_back(tmp_item);
    
    for (int i = 1; i < all_books.size(); i++)
    {
        for (int j = 0; j < kinds_books.size(); j++)
        {
            if (all_books[i].isbn() == kinds_books[j].isbn())
            {    
                number[j] += 1;
                break;
            }
            if (j == kinds_books.size() -1)
            {
                kinds_books.push_back(all_books[i]);
                number.push_back(1);
            }
        }
    }

    std::cout << "Start to print out" << std::endl;
    for (int i = 0; i < kinds_books.size(); i++)
        std::cout << kinds_books[i].isbn() << "    " << number[i] << std::endl;
    
    return 0;
}
