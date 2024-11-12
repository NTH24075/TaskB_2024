#ifndef LIST_STATISTIC_H
#define LIST_STATISTIC_H

#include "vector_build.h"
#include "statistic.cpp"
#include <fstream>
#include <iomanip>

class List_statistic {
private:
    Vector_build<statistic> statistic_list;
public:
    void add(statistic object);
    void write_to_file();
};

#endif
