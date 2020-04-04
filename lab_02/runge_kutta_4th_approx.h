#ifndef RUNGE_KUTTA_4TH_APPROX_H
#define RUNGE_KUTTA_4TH_APPROX_H

#include "funcs.h"

void Runge_Kutta_fourth_approx(double &I, double &U, param_t &p);

void count_fourth(double &k, double &m, double I, double U, param_t &p);

#endif // RUNGE_KUTTA_4TH_APPROX_H
