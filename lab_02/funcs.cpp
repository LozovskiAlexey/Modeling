#include "funcs.h"

/*
 * Все константы определены в defines.h, также
 * там определена структура parameters
 *
 * ! Во всех функциях param_t p - параметры пользователя !
*/

// Формирует вектора U, I (массивы значений для построения графиков)
void count_Runge_Kutta(std::vector<double> &U,std::vector<double> &I, param_t &p)
{
    auto tmp_U = p.Uc0; // стартовое значение U
    auto tmp_I = p.I0;  // стартовое значение I

    for (auto t=0.; t <= 700.; t += _dt)
    {
        U.push_back(tmp_U);
        I.push_back(tmp_I);

        Runge_Kutta(tmp_I, tmp_U, p);  // вычисляем новые значения I, U
    }
}

// Вычисляет методом Рунге-Кутты пару значений U, I
void Runge_Kutta(double &U, double &I, param_t &p)
{
    double k;                    // коэффициенты для вычисления 4 порядка точности
    double m;

    count_coeffs(k, m, I, U, p);    // вычисляем k, m

    U += _dt*m/6;                 // m = m1+m2+m3+m4
    I += _dt*k/6;                 // k = k1+k2+k3+k4
}

// Вычисляет коэф-ты K и M (используются в пошаговом Рунге-Кутта)
void count_coeffs(double &k, double &m, double I, double U, param_t &p)
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

// основные формулы лабы (см. методичку g(I))
double G(double I, param_t &p)
{
    return -I / p.Ck;
}

// основные формулы лабы (см. методичку F(I, U))
double F(double I, double U, param_t &p)
{
    return (U - I*(p.Rk - Rp(I))) / p.Lk;
}

// Вычисление параметра Rp функции F(I, U)
double Rp(const double &I)
{
    auto integral = integrate(I); // интегральное выражение в знаменателе

    return _const / integral;
}

// Интегрирование методом трапеций
double integrate(const double &I)
{
    auto step = 0.01;
    auto start = 0.;
    auto end = 1.;

    auto res = (count(start, I) + count(end, I)) / 2;

    for (auto z=step; z < end - step; z+=step)
        res += count(z, I);

    res *= step;

    return res;
}

// вычисляет подынтегральное выражение на каждом z
double count(const double &z, const double &I)
{
    double tmp_T = T(z, I);
    double tmp_sigma = sigma(tmp_T);

    return tmp_T * tmp_sigma * z;
}

// Параметр T используется для вычисления интеграла
double T(const double &z, const double &I)
{
    auto tmp_t0 = interpolate(_T0, _I, I); // вычисляем t0, m
    auto tmp_m = interpolate(_m, _I, I);

    return tmp_t0 + (_Tn - tmp_t0)*std::pow(z, tmp_m); // подставляем в формулу
}

// Параметр sigma используется для вычисления интеграла
double sigma(const double &T)
{
    auto tmp_sigma = log_interpolate(_sigma, _T, T);

    return tmp_sigma;
}

double interpolate(const std::vector<double> &vec1, const std::vector<double> &vec2, const double &key)
{
    size_t start, end;

    count_indexes(_I, start, end, key);  // вычисляем индексы для интерполяции

    // если значение есть в таблице - берем его, иначе интерполируем
    if (start == end)
        return vec1[start];
    else
        return vec1[start] + (vec1[end] - vec1[start]) * (key - vec2[start]) / (vec2[end] - vec2[start]);
}

double log_interpolate(const std::vector<double> &vec1, const std::vector<double> &vec2, const double &key)
{
    size_t start, end;

    count_indexes(_sigma, start, end, key); // вычисляем индексы для интерполяции

    // если значение есть в таблице - берем его, иначе интерполируем
    if (start == end)
        return vec1[start];
    else
    {
        auto res = std::log(vec1[start])+std::log(vec1[end]/vec1[start])*(key - vec2[start])/(vec2[end] - vec2[start]);
        return std::exp(res);
    }
}

// записывает граничные индексы в start, end между которыми
// расположено значение key
// в случае, если key находится за пределами массива, берутся первые либо последние два элемента для интерполяции
void count_indexes(const std::vector<double> &vec, size_t &start, size_t &end, const double &key)
{
    auto size = vec.size()-1;

    for (end=1; end<size; ++end)
        if (key <= vec[end])
            break;

    start = key == vec[end] ? end : end-1;
}
