#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <vector>

typedef struct params {
    // x_start = 0 по умолчанию
    double x_end;
    double step;

    double table_step;
    std::vector<double> table_intervals; // значения в таблице

    // генерация значений икс для вывода в консоль (задаются граничные значения и табличный шаг)
    void create_table_intervals(const double start, const double end, const double step)
    {
        for (auto i = start; i <= end; i += step)
            table_intervals.push_back(0.);
    }

    // заполнение структуры
    void init(const double x_end, const double step, const double table_step)
    {
        this->x_end = x_end;
        this->step = step;
        this->table_step = table_step;
    }
} params_t;

#endif // PARAMETERS_H
