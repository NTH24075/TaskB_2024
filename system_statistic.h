#ifndef SYSTEM_STATISTIC_H
#define SYSTEM_STATISTIC_H

#include "list_customer.cpp"
#include "list_call.cpp"
#include "list_statistic.cpp"

class systemStatistic {
private:
    List_customer customers_system;
    List_call called_system;
    List_statistic statistic_system;
public:
    systemStatistic();
    void getData();
    void run();
};

#endif
