#include "table.h"
#include "methods.h"

using namespace std;


int main()
{
    // ------------ Параметры для вывода ------------
            
    double x_end;
    double step;

    cout << "Set interval right limit (x_end): ";
    cin >> x_end;
    
    cout << "Set step: ";
    cin >> step;

    
    // ------------ Параметры для вывода ------------
    
    double table_x_start;
    double table_x_end;
    double table_step;

    cout << "Set table limits: ";
    cin >> table_x_start >> table_x_end;
    
    cout << "Set table step: ";
    cin >> table_step;

    size_t approx;
    cout << "Set Approx: ";
    cin >> approx;
    
    
    // ------------- Подготовка данных --------------
    
    table_t table;
    
    // ------------- Работа методов ------------------

    table.x_values = get_x_values(table_x_start, table_x_end, table_step); // формируем стобец значений x

    table.picard_2 = picard_method(table.x_values, approx);
    table.picard_3 = picard_method(table.x_values, approx+1);
    table.picard_n = picard_method(table.x_values, approx+2);
    table.explicit_result = explicit_method(table.x_values, step);
    table.implicit_result = implicit_method(table.x_values, step);

    // ------------- Вывод таблицы ------------------

    show(table);

    return 0;
}
