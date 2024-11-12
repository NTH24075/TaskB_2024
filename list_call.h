#ifndef LIST_CALL_H
#define LIST_CALL_H

#include "vector_build.h"
#include "infor_call.cpp"
#include <fstream>
#include <sstream>

class List_call {
private:
    Vector_build<infor_call> call_list;
public:
    void read_from_file();
    Vector_build<infor_call> getCall_list();
};

#endif
