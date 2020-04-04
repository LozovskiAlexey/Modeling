#include "runge_kutta_2nd_approx.h"


void Runge_Kutta_second_approx(double &I, double &U, param_t &p)
{
    double dU, dI;

    count_second(dU, dI, I, U, p);

    U += _dt*dU;
    I += _dt*dI;
}


void count_second(double &dU, double &dI, double I, double U, param_t &p)
{
    I += _dt * F(I, U, p) / 2.;
    U += _dt * G(I, p) / 2.;

    dI = F(I, U, p);
    dU = G(I,p);
}
