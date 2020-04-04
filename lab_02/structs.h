#ifndef SCTRUCTS_H
#define SCTRUCTS_H

#include <algorithm>
#include <QString>
#include <QColor>
#include <QVector>
#include <cmath>


// структура параметров, задаваемых пользователем
typedef struct parameters{
    double Lk;
    double Ck;
    double Rk;
    double Uc0;
    double I0;
}param_t;


// структура векторов значений функций
typedef struct graphic_points{
    QVector<double> t;
    QVector<double> Rp;
    QVector<double> I;
    QVector<double> U;
    QVector<double> Ucp;
    QVector<double> T0;
}graph_points_t;

// структура векторов значений параметров 2 и 4 приближений
typedef struct data{
    graph_points_t *second_approx;
    graph_points_t *fourth_approx;

    void init()
    {
        second_approx = new graph_points_t;
        fourth_approx = new graph_points_t;
    }

    void release()
    {
        delete second_approx;
        delete fourth_approx;
    }
}data_t;

// структура параметров графика
typedef struct graphic{
    QVector<double> X; // точки графика
    QVector<double> Y;
    QString xAxis;     // названия осей
    QString yAxis;
}graphic_t;

// структура графиков для отрисовки для одного приближения
typedef struct graphics{
    graphic_t *Rp;
    graphic_t *I;
    graphic_t *U;
    graphic_t *Ucp;
    graphic_t *T0;

    void init()
    {
        Rp = new graphic_t;
        I = new graphic_t;
        U = new graphic_t;
        Ucp = new graphic_t;
        T0 = new graphic_t;
    }
    void release()
    {
        delete Rp;
        delete I;
        delete U;
        delete Ucp;
        delete T0;
    }
}graphics_t;

// структура графиков для каждого приближения
typedef struct draw_data{
    graphics_t *second_approx;
    graphics_t *fourth_approx;

    void init()
    {
        second_approx = new graphics_t;
        fourth_approx = new graphics_t;

        second_approx->init();
        fourth_approx->init();
    }

    void release()
    {
        second_approx->release();
        fourth_approx->release();

        delete second_approx;
        delete fourth_approx;
    }
}draw_data_t;

#endif // SCTRUCTS_H
