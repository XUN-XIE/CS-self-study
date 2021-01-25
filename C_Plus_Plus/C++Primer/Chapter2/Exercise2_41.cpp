#include <iostream>
#include <string>

struct Sales_data
{
    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() 
{
    Sales_data total;
    std::string isbn;
    unsigned units_sold;
    double revenue;

    if (std::cin >> isbn >> units_sold >> revenue) {
        total.isbn = isbn;
        total.units_sold = units_sold;
        total.revenue = revenue;

        Sales_data trans;
        while (std::cin >> isbn >> units_sold >> revenue) {
            trans.isbn = isbn;
            trans.units_sold = units_sold;
            trans.revenue = revenue;
            if (total.isbn == trans.isbn)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                std::cout << total.isbn << "\t" << total.units_sold << "\t" << total.revenue << std::endl;
                total.isbn = trans.isbn;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << total.isbn << "\t" << total.units_sold << "\t" << total.revenue << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;

        return -1;
    }
    
    return 0;
}