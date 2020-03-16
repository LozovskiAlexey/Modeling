#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

static const double PI = 3.141592653589793;

static const double _R  = 0.35;
static const double _Le = 12.0;
static const double _Tn = 2000.0;
static const double _dt = 1e-6;

// Таблица для интерполяции параметров T0, m
static const std::vector<double> _I { 0.5, 1, 5, 10, 50, 200, 400, 800, 1200 };
static const std::vector<double> _T0{ 6400, 6790, 7150, 7270, 8010, 9185, 10010, 11140, 12010};
static const std::vector<double> _m {0.4, 0.55, 1.7, 3, 11, 32, 40, 41, 39};

// Таблица для интерполяции сигмы
static const std::vector<double> _T    {4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000,13000, 14000};
static const std::vector<double> _sigma{0.031, 0.27, 2.05, 6.06, 12.0, 19.9, 29.6, 41.1, 54.1, 67.7, 81.5};

// структура параметров, задаваемых пользователем
typedef struct parameters {
    const double Lk;
    const double Ck;
    const double Rk;
    const double Uco;
    const double I0;
}param_t;

#endif // DEFINES_H
