#ifndef RUNGE_KUTTA_4TH_APPROX_H
#define RUNGE_KUTTA_4TH_APPROX_H

#include "funcs.h"

void Runge_Kutta_4th_approx(double &U, double &I, param_t &p);

// вычисляет коэффициенты k, m для вычисления 4 порядка точности
void count_coeffs(double &k, double &m, double I, double U, param_t &p);
#endif // RUNGE_KUTTA_4TH_APPROX_H
