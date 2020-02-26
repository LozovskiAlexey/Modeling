#include "table.h"

void show(table_t& table){

    auto x = table.x_values;
    auto picard2 = table.picard_2;
    auto picard3 = table.picard_3;
    auto picardn = table.picard_n;
    auto explicit_method_result = table.explicit_result;
    auto implicit_method_result = table.implicit_result;

    auto rows = x.size();
    int width = 8;

    std::cout.precision(4);
    std::cout.setf(std::ios::fixed);

    std::cout << std::endl;

    std::cout << "         |" << "         Picard (approx)        |" << "          |" << "          |" << std::endl;
    std::cout << "    X    |" << "    2nd   |   3rd    |    n     |" << " Explicit |" << " Implicit |" << std::endl;
    std::cout << "         |" << "          |          |          |" << "          |" << "          |" << std::endl;
    for (size_t row=0.; row<rows; ++row)
    {
        std::cout.width(width);
        std::cout << std::left << x[row] << " | "; std::cout.width( width);
        std::cout << std::left << picard2[row] << " | " ; std::cout.width(width);
        std::cout << std::left << picard3[row] << " | " ; std::cout.width(width);
        std::cout << std::left << picardn[row] << " | " ; std::cout.width(width);
        std::cout << std::left << explicit_method_result[row] << " | " ; std::cout.width(width);
        std::cout << std::left << implicit_method_result[row] << " | " ; std::cout.width(width);
        std::cout << std::endl;
    }
}
