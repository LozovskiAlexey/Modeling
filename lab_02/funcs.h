#ifndef FUNCS_H
#define FUNCS_H

#include "defines.h"
#include <cmath>

// p - заданные пользователем параметры
void count_Runge_Kutta(std::vector<double> &U,std::vector<double> &I, param_t &p);
void Runge_Kutta(double &U, double &I, param_t &p);


// вычисляет коэффициенты k, m для вычисления 4 порядка точности
void count_coeffs(double &k, double &m, double I, double U, param_t &p);


// основные функции программы, уравнения, которые нужно решить
double F(double I, double U, param_t &p);
double G(double I, param_t &p);


// вспомогательные функции для нахождения значений функции F(I, U)
double Rp(const double &I);
double integrate(const double &I);
double count(const double &z, const double &I);
double T(const double &z, const double &I);
double m(const double &I);
double sigma(const double &T);


// интерполяция и логарифмическая интерполяция
double log_interpolate(const std::vector<double> &vec1, const std::vector<double> &vec2, const double &key);
double interpolate(const std::vector<double> &vec1, const std::vector<double> &vec2, const double &key);
void count_indexes(const std::vector<double> &vec, size_t &start, size_t &end, const double &key);


#endif // FUNCS_H
