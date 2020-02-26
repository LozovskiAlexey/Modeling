#include "methods.h"


std::vector<double> get_x_values(const double table_x_start, const double table_x_end, const double table_step)
{
    col_t x_values;
    for (auto x = table_x_start; x <= table_x_end + table_step; x += table_step){
        x_values.push_back(x);
    }

    return x_values;
}


std::vector<double> explicit_method(const col_t x_values, const double step)
{
    size_t tmp_step = 1; 
    auto steps = x_values.size();
    
    auto y = 0.; 
    auto result = std::vector<double> {y};

    // начинаем с x = h, в массивах уже лежат  x_values: {x0 = 0}, result: {y0 = 0} 
    for (auto x=step; tmp_step<steps; x+=step){
        y += step * (x*x + y*y);
        
        // Если дошли до табличного икса - записываем в результат
        if (x+step >= x_values[tmp_step]){
            ++tmp_step;
            result.push_back(y);
        }
    }
    return result;
}


std::vector<double> implicit_method(const col_t x_values, const double step)
{
    size_t tmp_step = 1; 
    auto steps = x_values.size();
    
    auto y = 0.; 
    auto result = std::vector<double> {y};

    for (auto x=step; tmp_step<steps; x+=step){

        auto d = 1-4*step*(y+step*x*x);
        y = (1 - sqrt(d)) / (2*step);

        if (x+step >= x_values[tmp_step]){
            ++tmp_step;
            result.push_back(y);
        }
    }
    return result;
}


std::vector<double> picard_method(const col_t x_values, const size_t approximation)
{
    Polinomial start(1, 2);
    Polinomial result_polinomial = start.integrate();

    for (size_t i=1; i<approximation; ++i)
    {
        auto squared = result_polinomial * result_polinomial;
        auto tmp_polinomial = start + squared;
        result_polinomial = tmp_polinomial.integrate();
    }

    auto result = std::vector<double>();

    for (size_t i=0; i<x_values.size(); ++i)
        result.push_back(result_polinomial.count(x_values[i]));

    return result;
}
