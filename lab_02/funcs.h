#ifndef FUNCS_H
#define FUNCS_H

#include "defines.h"

// основные функции программы, уравнения, которые нужно решить
double F(double I, double U, param_t &p);
double G(double I, param_t &p);


// вспомогательные функции для нахождения значений функции F(I, U)
double Rp(const double &I);
double T(const double &z, const double &I);
double T0(const double &I);
double m(const double &I);
double sigma(const double &T);


double integrate(double start, double end, const double &I);
double count(const double &z, const double &I);


// интерполяция и логарифмическая интерполяция
double log_interpolate(const QVector<double> &vec1, const QVector<double> &vec2, const double &key);
double interpolate(const QVector<double> &vec1, const QVector<double> &vec2, const double &key);
void count_indexes(const QVector<double> &vec, int &start, int &end, const double &key);


#endif // FUNCS_H
