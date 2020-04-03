#ifndef SCTRUCTS_H
#define SCTRUCTS_H

#include <algorithm>
#include <QString>
#include <QColor>
#include <QVector>
#include <cmath>

// пара графиков для второго и четвертого порядков приближения
typedef struct parameters param_t;

typedef struct data data_t;
typedef struct graphic_points graph_points_t;

typedef struct draw_data draw_data_t;
typedef struct graphics graphics_t;
typedef struct graphic graphic_t;


// структура параметров, задаваемых пользователем
struct parameters{
    double Lk;
    double Ck;
    double Rk;
    double Uc0;
    double I0;
};


// структура векторов значений параметров 2 и 4 приближений
struct data{
    graph_points_t *second_approx;
    graph_points_t *fourth_approx;
} ;


// структура векторов значений функций
struct graphic_points{
    QVector<double> t;
    QVector<double> Rp;
    QVector<double> I;
    QVector<double> U;
    QVector<double> Ucp;
    QVector<double> T0;
};

// структура графиков для каждого приближения
struct draw_data{
    graphics_t *second_approx;
    graphics_t *fourth_approx;
};


// структура графиков для отрисовки для одного приближения
struct graphics{
    graphic_t *Rp;
    graphic_t *I;
    graphic_t *U;
    graphic_t *Ucp;
    graphic_t *T0;
};


// структура параметров графика
struct graphic{
    QVector<double> X; // точки графика
    QVector<double> Y;
    QString xAxis;     // названия осей
    QString yAxis;
};

#endif // SCTRUCTS_H
