#ifndef MAIN_FUNCS_H
#define MAIN_FUNCS_H

#include "runge_kutta_2nd_approx.h"
#include "runge_kutta_4th_approx.h"
#include "structs.h"
#include "funcs.h"

void countAll(data_t &data, param_t &p);

void count_approx(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&));

void count_U_I(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&));
void count_Rp(graph_points_t *data);
void count_Ucp(graph_points_t *data);
void count_T0(graph_points_t *data);

void count_Rp(QVector<double> &Rp, QVector<double> &I);
void count_Ucp(QVector<double> &Ucp, QVector<double> &U, QVector<double> &I);
void count_T0(QVector<double> &T0, QVector<double> &I);



void form_graphs(draw_data_t &graphics, data_t &data);

void generate_graphs(graphics_t *graphics, graph_points_t *data);

void generate_Rp_graphic(graphic_t *Rp, graph_points_t *data);
void generate_I_graphic(graphic_t *I, graph_points_t *data);
void generate_U_graphic(graphic_t *U, graph_points_t *data);
void generate_Ucp_graphic(graphic_t *Ucp, graph_points_t *data);
void generate_T0_graphic(graphic_t *T0, graph_points_t *data);

graphic_t *init(QVector<double> &X, QVector<double> &Y, QString xAxis, QString yAxis);
#endif // MAIN_FUNCS_H
