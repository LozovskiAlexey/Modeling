#ifndef METHODS_H
#define METHODS_H

#include "polinomial.h"
#include "table.h"

std::vector<double> get_x_values(const double x_end, const double step);
std::vector<double> explicit_method(const col_t x_values, const double step);
std::vector<double> implicit_method(const col_t x_values, const double step);
std::vector<double> picard_method(const col_t x_values, const size_t approximation);

double explicit_method(const double step);
double implicit_method(const double step);

#endif // METHODS_H
