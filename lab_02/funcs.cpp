#include "funcs.h"

// Основные формулы лабы (см. методичку g(I))
double G(double I, param_t &p)
{   
    return -I / p.Ck;
}

// Основные формулы лабы (см. методичку F(I, U))
double F(double I, double U, param_t &p)
{
    return (U - I*(p.Rk + Rp(I))) / p.Lk;
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

// Вычисляет подинтегральное выражение на каждом z
double count(const double &z, const double &I)
{
    double tmp_T = T(z, I);
    double tmp_sigma = sigma(tmp_T);

    return tmp_sigma * z;
}

double T0(const double &I)
{
    return interpolate(_T0, _I, I);
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

double interpolate(const QVector<double> &vec1, const QVector<double> &vec2, const double &key)
{
    int start, end;

    count_indexes(vec2, start, end, key);  // вычисляем индексы для интерполяции

    // если значение есть в таблице - берем его, иначе интерполируем
    if (start == end)
        return vec1[start];
    else
        return vec1[start] + (vec1[end] - vec1[start]) * (key - vec2[start]) / (vec2[end] - vec2[start]);
}

double log_interpolate(const QVector<double> &vec1, const QVector<double> &vec2, const double &key)
{
    int start, end;

    count_indexes(vec2, start, end, key); // вычисляем индексы для интерполяции

    // если значение есть в таблице - берем его, иначе интерполируем
    if (start == end)
        return vec1[start];
    else
    {
        auto res = std::log(vec1[start])+std::log(vec1[end]/vec1[start])*(key - vec2[start])/(vec2[end] - vec2[start]);
        return std::exp(res);
    }
}

// Записывает граничные индексы в start, end между которыми
// расположено значение key
// в случае, если key находится за пределами массива, берутся первые либо последние два элемента для интерполяции
void count_indexes(const QVector<double> &vec, int &start, int &end, const double &key)
{
    auto size = vec.size()-1;

    for (end=1; end<size; ++end)
        if (key <= vec[end])
            break;

    start = key == vec[end] ? end : end-1;
}
