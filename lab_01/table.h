#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>

using col_t = std::vector<double>;
typedef struct table{
    col_t x_values;
    col_t picard_2;
    col_t picard_3;
    col_t picard_n;
    col_t explicit_result;
    col_t implicit_result;

} table_t;


void show(table_t& table);


#endif // TABLE_H
