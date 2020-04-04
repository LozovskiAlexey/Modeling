#include "main_funcs.h"

// Вычисление компонентов для каждого приближения (второго и четвертого)

// Вычисление векторов
void count_all(data_t &data, param_t &p)
{
    // Распараллелить
    count_params(data.fourth_approx, p, Runge_Kutta_fourth_approx);
    count_params(data.second_approx, p, Runge_Kutta_second_approx);
}

// Формирование графиков для отрисовки
void generate_graphs(draw_data_t &graphics, data_t &data)
{
    generate_graphs(graphics.second_approx, data.second_approx);
    generate_graphs(graphics.fourth_approx, data.fourth_approx);
}

// Вычисление каждого компонента
// =============================================================================================

// Вычисление векторов значений (зависимых от t)
void count_params(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&))
{
    count_U_I(data, p, method);
    count_Rp(data);
    count_Ucp(data);
    count_T0(data);
}

//
void generate_graphs(graphics_t *graphics, graph_points_t *data)
{
    generate_Rp_graphic(graphics->Rp, data);
    generate_I_graphic(graphics->I, data);
    generate_U_graphic(graphics->U, data);
    generate_Ucp_graphic(graphics->Ucp, data);
    generate_T0_graphic(graphics->T0, data);
}

// Вычисление каждого вектора отдельно
// =============================================================================================

void count_U_I(graph_points_t *data, param_t &p, void (*method)(double&, double&, param_t&))
{
    count_Runge_Kutta(data->t, data->I, data->U, p, method);
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

// Инициализация каждой структуры графика для отрисовки

void generate_Rp_graphic(graphic_t *Rp, graph_points_t *data)
{
    init(Rp, data->I, data->Rp, "t", "Rp");
}

void generate_I_graphic(graphic_t *I, graph_points_t *data)
{
    init(I, data->t, data->I, "t", "I");
}

void generate_U_graphic(graphic_t *U, graph_points_t *data)
{
    init(U, data->t, data->U, "t", "U");
}

void generate_Ucp_graphic(graphic_t *Ucp, graph_points_t *data)
{
    init(Ucp, data->t,data->Ucp, "t", "Ucp");
}

void generate_T0_graphic(graphic_t *T0, graph_points_t *data)
{
    init(T0, data->t, data->T0, "t", "T0");
}

// Реализация вычислений
// =============================================================================================

void count_Runge_Kutta(QVector<double> &T, QVector<double> &I, QVector<double> &U, param_t &p, void (*method)(double&, double&, param_t&))
{
    auto tmp_U = p.Uc0; // стартовое значение U
    auto tmp_I = p.I0;  // стартовое значение I

    for (auto t=0.; t <= _tmax; t += _dt)
    {
        U.push_back(tmp_U);
        I.push_back(tmp_I);
        T.push_back(t);

        method(tmp_I, tmp_U, p);  // вычисляем новые значения I, U
    }
}

// Распараллелить
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

// Распараллелить
void count_T0(QVector<double> &_T0, QVector<double> &I)
{
    for (auto tmp_I : I)
        _T0.push_back(T0(tmp_I));
}

// функции инициализации, выделения и освобождения памяти
// ============================================================================================

void init(graphic_t *graphic, QVector<double> &X, QVector<double> &Y, QString xAxis, QString yAxis)
{
    graphic->X = X;
    graphic->Y = Y;
    graphic->xAxis = xAxis;
    graphic->yAxis = yAxis;
}

void init(data_t &structure)
{
    structure.init();
}

void release(data_t &structure)
{
    structure.release();
}

void init(draw_data_t &structure)
{
    structure.init();
}

void release(draw_data_t &structure)
{
    structure.release();
}

