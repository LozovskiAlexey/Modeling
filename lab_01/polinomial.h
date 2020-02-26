#ifndef POLINOMIAL_H
#define POLINOMIAL_H

#include <iostream>
#include <vector>
#include <cmath>

class Polinomial
{
public:
    Polinomial(const size_t power);
    Polinomial(const double coeff, const size_t power); // коэффициент, степень

    // умножение полиномов
    Polinomial operator*(const Polinomial &obj);

    // сложение полиномов
    Polinomial operator+(const Polinomial &obj);

    // интегрирование полинома
    Polinomial integrate();

    void set(const size_t power, const double coeff);

    double count(const double x);
    void show();

private:
    // вектор, в котором хранится полином
    // индекс элемента - степень, значение элемента - коэф-т при х
    std::vector<double> polinomial;

    size_t _power;                   // степень полинома
};

#endif // POLINOMIAL_H
