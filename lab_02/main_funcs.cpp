#include "main_funcs.h"

void count_all(data_t &data, param_t &p)
{
    count_approx(data.fourth_approx, p, Runge_Kutta_4th_approx);
    count_approx(data.second_approx, p, Runge_Kutta_2nd_approx);
}

// =============================================================================================

void count_approx(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&))
{
    init(data);

    count_U_I(data, p, method);
    count_Rp(data);
    count_Ucp(data);
    count_T0(data);
}

// =============================================================================================

void count_U_I(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&))
{
    count_Runge_Kutta(data->t, data->U, data->I, p, method);
}


void count_Rp(graph_points_t *data)
{
    count_Rp(data->Rp, data->I);
}


void count_Ucp(graph_points_t *data)
{
    count_Ucp(data->Ucp, data->U, data->I);
}


void count_T0(graph_points_t *data)
{
    count_T0(data->T0, data->I);
}

// =============================================================================================


void count_Runge_Kutta(QVector<double> &T, QVector<double> &U, QVector<double> &I, param_t &p, void (*method)(double&, double&, param_t&))
{
    auto tmp_U = p.Uc0; // стартовое значение U
    auto tmp_I = p.I0;  // стартовое значение I

    for (auto t=0.; t <= 700.; t += _dt)
    {
        U.push_back(tmp_U);
        I.push_back(tmp_I);
        T.push_back(t);

        method(tmp_I, tmp_U, p);  // вычисляем новые значения I, U
    }
}


void count_Rp(QVector<double> &_Rp, QVector<double> &I)
{
    for (auto tmp_I : I)
        _Rp.push_back(Rp(tmp_I));
}


void count_Ucp(QVector<double> &_Ucp, QVector<double> &U, QVector<double> &I)
{
    for (int i=0; i<I.size(); ++i)
        _Ucp.push_back(U[i]*I[i]);
}


void count_T0(QVector<double> &_T0, QVector<double> &I)
{
    for (auto tmp_I : I)
        _T0.push_back(T0(tmp_I));
}

// =============================================================================================


void form_graphs(draw_data_t &graphics, data_t &data)
{
    generate_graphs(graphics.second_approx, data.second_approx);
    generate_graphs(graphics.fourth_approx, data.fourth_approx);
}


void generate_graphs(graphics_t *graphics, graph_points_t *data)
{
    init(graphics);

    generate_Rp_graphic(graphics->Rp, data);
    generate_I_graphic(graphics->I, data);
    generate_U_graphic(graphics->U, data);
    generate_Ucp_graphic(graphics->Ucp, data);
    generate_T0_graphic(graphics->T0, data);
}


// ============================================================================================

void generate_Rp_graphic(graphic_t *Rp, graph_points_t *data)
{
    init(Rp, data->Rp, data->I, "Rp", "t");
}

void generate_I_graphic(graphic_t *I, graph_points_t *data)
{
    init(I, data->I, data->t, "I", "t");
}

void generate_U_graphic(graphic_t *U, graph_points_t *data)
{
    init(U, data->U, data->t, "U", "t");
}

void generate_Ucp_graphic(graphic_t *Ucp, graph_points_t *data)
{
    init(Ucp, data->Ucp, data->t, "Ucp", "t");
}

void generate_T0_graphic(graphic_t *T0, graph_points_t *data)
{
    init(T0, data->T0, data->t, "T0", "t");
}

// ============================================================================================

void init(graphic_t *graphic, QVector<double> &X, QVector<double> &Y, QString xAxis, QString yAxis)
{
    graphic = new graphic_t;

    graphic->X = X;
    graphic->Y = Y;
    graphic->xAxis = xAxis;
    graphic->yAxis = yAxis;
}

void init(graphics_t *data)
{
    data = new graphics_t;
}

void init(graph_points_t *data)
{
    data = new graph_points_t;
}
