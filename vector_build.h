#ifndef VECTOR_BUILD_H
#define VECTOR_BUILD_H

#include <iostream>
using namespace std;
template<typename data>
class Vector_build {
private:
    int size_v;
    int cap;
    data* dynamic_array;

public:
    Vector_build();
    Vector_build(int n, data DT);
    ~Vector_build();

    class iterator {
    private:
        data* curr;
    public:
        iterator(data* p = NULL);
        iterator& operator++();
        iterator operator++(int);
        iterator operator+(int n);
        int operator-(const iterator& it) const;
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
        data& operator*();
        template<typename T>
        friend ostream& operator<<(ostream& os, const typename Vector_build<T>::iterator& it);
    };

    void resize();
    bool empty();
    int size();
    void clear();
    void push_back(data push_to_list);
    void del_data(data data_remove);
    void remove(int index);
    iterator begin();
    iterator back();
    iterator end();
    Vector_build<data> operator+(Vector_build<data>& other_vector);
    bool operator==(Vector_build<data>& other_vector);
    data& operator[](int index);
};

#include "vector_build.cpp" // Include template implementation
#endif
