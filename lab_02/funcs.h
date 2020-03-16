#ifndef FUNCS_H
#define FUNCS_H

#include "defines.h"

// для интерполяции используем два массива и параметр:
// параметр - аргумент, от которого ищется значение. Например,
// T(i) - значение, которое ищем, в функцию передаем i, как параметр
double log_interpolate(const std::vector<double> &,const std::vector<double> &,const double &);
double interpolate(const std::vector<double> &,const std::vector<double> &, const double &);


// parameters - заданные пользователем параметры
void Runge_Kutta_method(std::vector<double> &U,std::vector<double> &I, param_t &p);
void Runge_Kutta(double &U, double &I, param_t&);


// вычисляет коэффициенты k, m для вычисления 4 порядка точности
void count_coeffs(double &k, double &m, double I, double U, param_t&);


// основные функции программы, уравнения, которые нужно решить
double F(double I, double U, param_t &p);
double G(double I, param_t &p);


// вспомогательные функции для нахождения значений функции F(I, U)
double Rp(const double &);
double T(double &z, double &I);
double integrate(double &I);


#endif // FUNCS_H
