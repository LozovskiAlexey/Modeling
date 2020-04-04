#ifndef RUNGE_KUTTA_2ND_APPROX_H
#define RUNGE_KUTTA_2ND_APPROX_H

#include "funcs.h"

void Runge_Kutta_second_approx(double &I, double &U, param_t &p);

void count_second(double &dU, double &dI, double I, double U, param_t &p);
#endif // RUNGE_KUTTA_2ND_APPROX_H
