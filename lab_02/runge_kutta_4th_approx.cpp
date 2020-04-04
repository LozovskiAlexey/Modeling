#include "runge_kutta_4th_approx.h"


// Вычисляет методом Рунге-Кутты пару значений U, I
void Runge_Kutta_fourth_approx(double &I, double &U, param_t &p)
{
    double k;                    // коэффициенты для вычисления 4 порядка точности
    double m;

    count_fourth(k, m, I, U, p);    // вычисляем k, m

    U += m/6;                 // m = m1+2m2+2m3+m4
    I += k/6;                 // k = k1+2k2+2k3+k4
}


// Вычисляет коэф-ты K и M (используются в пошаговом Рунге-Кутта)
void count_fourth(double &k, double &m, double I, double U, param_t &p)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    // расчет коэффициентов k и m
    m1 = _dt*G(I, p);
    k1 = _dt*F(I, U, p);

    m2 = _dt*G(I+k1/2, p);
    k2 = _dt*F(I+k1/2, U+m1/2, p);

    m3 = _dt*G(I+k2/2, p);
    k3 = _dt*F(I+k2/2, U+m2/2, p);

    m4 = _dt*G(I+k3, p);
    k4 = _dt*F(I+k3, U+m3, p);

    // в результирующие переменные запишем сумму
    k = k1 + 2*k2 + 2*k3 + k4;
    m = m1 + 2*m2 + 2*m3 + m4;
}
