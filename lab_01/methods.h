#ifndef METHODS_H
#define METHODS_H

#include "polinomial.h"
#include "table.h"

std::vector<double> get_x_values(const double table_x_start, const double table_x_end, const double step);
std::vector<double> explicit_method(const col_t x_values, const double step);
std::vector<double> implicit_method(const col_t x_values, const double step);
std::vector<double> picard_method(const col_t x_values, const size_t approximation);

#endif // METHODS_H
