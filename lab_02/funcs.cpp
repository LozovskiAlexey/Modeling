#include "funcs.h"

// p - параметры, введенные пользователем
void Runge_Kutta_method(std::vector<double> &U,std::vector<double> &I, param_t &p)
{
    auto tmp_U = p.Uco; // стартовое значение U
    auto tmp_I = p.I0;  // стартовое значение I

    for (auto t=0.; t <= 700.; t += _dt)
    {
        U.push_back(tmp_U);
        I.push_back(tmp_I);

        Runge_Kutta(tmp_I, tmp_U, p);  // вычисляем новые значения I, U
    }
}


// Рунге-Кутта на каждом шаге
// p - параметры, введенные пользователем
void Runge_Kutta(double &U, double &I, param_t &p)
{
    double k;                    // коэффициенты для вычисления 4 порядка точности
    double m;

    count_coeffs(k, m, I, U, p);    // вычисляем k, m

    U += _dt*m/6;                 // m = m1+m2+m3+m4
    I += _dt*k/6;                 // k = k1+k2+k3+k4
}


// Вычисляет коэф-ты K и M
// Просто закодил формулу, причем максимально тупым образом
// p - параметры, введенные пользователем
void count_coeffs(double &k, double &m, double I, double U, param_t &p)
{
    double k1, k2, k3, k4;
    double m1, m2, m3, m4;

    m1 = G(I, p);
    k1 = F(I, U, p);

    m2 = G(I+_dt*k1/2, p);
    k2 = F(I+_dt*k1/2, U+_dt*m1/2, p);

    m3 = G(I+_dt*k2/2, p);
    k3 = F(I+_dt*k2/2, U+_dt*m2/2, p);

    m4 = G(I+_dt*k3/2, p);
    k4 = F(I+_dt*k3/2, U+_dt*m3/2, p);

    k = k1 + 2*k2 + 2*k3 + k4;
    m = m1 + 2*m2 + 2*m3 + m4;
}

// p - параметры, введенные пользователем
double G(double I, param_t &p)
{
    return -I / p.Ck;
}

double F(double I, double U, param_t &p)
{
    return (U - I*(p.Rk - Rp(I))) / p.Lk;
}


double Rp(const double I)
{
    double Rp = _Le / (2*_R*_R*PI);

    auto integral = integrate(I);

    Rp /= integral;

    return Rp;
}


double integrate(const double I)
{

}
