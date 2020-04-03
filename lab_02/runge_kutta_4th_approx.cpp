#include "runge_kutta_4th_approx.h"


// Вычисляет методом Рунге-Кутты пару значений U, I
void Runge_Kutta_fourth_approx(double &U, double &I, param_t &p)
{
    double k;                    // коэффициенты для вычисления 4 порядка точности
    double m;

    count(k, m, I, U, p);    // вычисляем k, m

    U += _dt*m/6;                 // m = m1+2m2+2m3+m4
    I += _dt*k/6;                 // k = k1+2k2+2k3+k4
}


// Вычисляет коэф-ты K и M (используются в пошаговом Рунге-Кутта)
void count(double &k, double &m, double I, double U, param_t &p)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    // расчет коэффициентов k и m
    m1 = G(I, p);
    k1 = F(I, U, p);

    m2 = G(I+_dt*k1/2, p);
    k2 = F(I+_dt*k1/2, U+_dt*m1/2, p);

    m3 = G(I+_dt*k2/2, p);
    k3 = F(I+_dt*k2/2, U+_dt*m2/2, p);

    m4 = G(I+_dt*k3/2, p);
    k4 = F(I+_dt*k3/2, U+_dt*m3/2, p);

    // в результирующие переменные запишем сумму
    k = k1 + 2*k2 + 2*k3 + k4;
    m = m1 + 2*m2 + 2*m3 + m4;
}
