#ifndef DEFINES_H
#define DEFINES_H

#include "structs.h"

static const QVector<QColor> color {Qt::red, Qt::blue};

static const double _tmax = 800e-6;
static const double _dt = 5e-7;

static const double PI = 3.141592653589793;

static const double _R  = 0.35;
static const double _Le = 12.0;
static const double _Tn = 2000.0;

static const double _const = _Le / (2*_R*_R*PI);

// Таблица для интерполяции параметров T0, m

static const QVector<double> _I { 0.5, 1, 5, 10, 50, 200, 400, 800, 1200 };
static const QVector<double> _T0{ 6700, 6790, 7150, 7270, 8010, 9185, 10010, 11140, 12010};
static const QVector<double> _m {0.5, 0.55, 1.7, 3, 11, 32, 40, 41, 39};

// Таблица для интерполяции сигмы

static const QVector<double> _T    {4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000,13000, 14000};
static const QVector<double> _sigma{0.031, 0.27, 2.05, 6.06, 12.0, 19.9, 29.6, 41.1, 54.1, 67.7, 81.5};


#endif // DEFINES_H
