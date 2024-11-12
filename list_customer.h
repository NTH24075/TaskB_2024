#ifndef LIST_CUSTOMER_H
#define LIST_CUSTOMER_H

#include "vector_build.h"
#include "infor_user.cpp"
#include <fstream>
#include <sstream>

class List_customer {
private:
    Vector_build<infor_user> customers_list;
public:
    void read_from_file();
    Vector_build<infor_user> getCustomer_list();
};

#endif
