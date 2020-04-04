#ifndef MAIN_FUNCS_H
#define MAIN_FUNCS_H

#include "runge_kutta_2nd_approx.h"
#include "runge_kutta_4th_approx.h"


void count_all(data_t &data, param_t &p);
void generate_graphs(draw_data_t &graphics, data_t &data);


void count_params(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&));
void generate_graphs(graphics_t *graphics, graph_points_t *data);


void count_U_I(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&));
void count_Rp(graph_points_t *data);
void count_Ucp(graph_points_t *data);
void count_T0(graph_points_t *data);

void generate_Rp_graphic(graphic_t *Rp, graph_points_t *data);
void generate_I_graphic(graphic_t *I, graph_points_t *data);
void generate_U_graphic(graphic_t *U, graph_points_t *data);
void generate_Ucp_graphic(graphic_t *Ucp, graph_points_t *data);
void generate_T0_graphic(graphic_t *T0, graph_points_t *data);


void count_Runge_Kutta(QVector<double> &T, QVector<double> &I, QVector<double> &U, param_t &p, void (*method)(double&, double&, param_t&));
void count_Ucp(QVector<double> &Ucp, QVector<double> &U, QVector<double> &I);
void count_Rp(QVector<double> &Rp, QVector<double> &I);
void count_T0(QVector<double> &T0, QVector<double> &I);


void init(graphic_t *graphic, QVector<double> &X, QVector<double> &Y, QString xAxis, QString yAxis);

void init(data_t &structure);
void release(data_t &structure);

void init(draw_data_t &structure);
void release(draw_data_t &structure);

#endif // MAIN_FUNCS_H
