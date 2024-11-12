#ifndef VECTOR_BUILD_CPP
#define VECTOR_BUILD_CPP

#include "vector_build.h"

template<typename data>
Vector_build<data>::Vector_build() : size_v(0), cap(1) {
    dynamic_array = new data[1];
}

template<typename data>
Vector_build<data>::Vector_build(int n, data DT) : size_v(n), cap(n) {
    dynamic_array = new data[cap];
}

template<typename data>
Vector_build<data>::~Vector_build() {
    delete[] dynamic_array;
}

template<typename data>
Vector_build<data>::iterator::iterator(data* p) : curr(p) {}

template<typename data>
typename Vector_build<data>::iterator& Vector_build<data>::iterator::operator++() {
    curr++;
    return *this;
}

template<typename data>
typename Vector_build<data>::iterator Vector_build<data>::iterator::operator++(int) {
    iterator temp = *this;
    curr++;
    return temp;
}

template<typename data>
typename Vector_build<data>::iterator Vector_build<data>::iterator::operator+(int i) {
    return iterator(curr + i);
}

template<typename data>
int Vector_build<data>::iterator::operator-(const iterator& it) const {
    return this->curr - it.curr;
}

template<typename data>
bool Vector_build<data>::iterator::operator==(const iterator& other_iterator) const {
    return this->curr == other_iterator.curr;
}

template<typename data>
bool Vector_build<data>::iterator::operator!=(const iterator& other_iterator) const {
    return !(other_iterator == *this);
}

template<typename data>
data& Vector_build<data>::iterator::operator*() {
    return *curr;
}

template<typename T>
ostream& operator<<(ostream& os, const typename Vector_build<T>::iterator& it) {
    os << *(it.curr);
    return os;
}

template<typename data>
void Vector_build<data>::resize() {
    if(cap > size_v) return;
    cap = size_v * 2;
    data* temp = new data[cap];
    for(int i = 0; i < size_v; i++) {
        temp[i] = dynamic_array[i];
    }
    delete[] dynamic_array;
    dynamic_array = temp;
}

template<typename data>
bool Vector_build<data>::empty() {
    return size_v == 0;
}

template<typename data>
int Vector_build<data>::size() {
    return size_v;
}

template<typename data>
void Vector_build<data>::clear() {
    size_v = 0;
}

template<typename data>
void Vector_build<data>::push_back(data push_to_list) {
    resize();
    dynamic_array[size_v++] = push_to_list;
}

template<typename data>
void Vector_build<data>::del_data(data data_remove) {
    int tmp_size = size_v;
    for(int i = 0; i < size_v; i++) {
        if(dynamic_array[i] == data_remove) {
            for(int j = i; j < size_v; j++) {
                dynamic_array[i] = dynamic_array[i+1];
            }
            size_v--;
        }
    }
}

template<typename data>
void Vector_build<data>::remove(int index) {
    if(index < size_v && size_v != 0) {
        for(int i = index; i < size_v; i++) {
            dynamic_array[i] = dynamic_array[i+1];
        }
        size_v--;
    }
}

template<typename data>
typename Vector_build<data>::iterator Vector_build<data>::begin() {
    return iterator(dynamic_array);
}

template<typename data>
typename Vector_build<data>::iterator Vector_build<data>::back() {
    return iterator(dynamic_array + size_v - 1);
}

template<typename data>
typename Vector_build<data>::iterator Vector_build<data>::end() {
    return iterator(dynamic_array + size_v);
}

template<typename data>
Vector_build<data> Vector_build<data>::operator+(Vector_build<data>& other_vector) {
    Vector_build<data> tmp_vec;
    for(int i = 0; i < max(size_v, other_vector.size()); i++) {
        tmp_vec.push_back(dynamic_array[i] + other_vector[i]);
    }
    return tmp_vec;
}

template<typename data>
bool Vector_build<data>::operator==(Vector_build<data>& other_vector) {
    if(other_vector.size() != size_v)
        return false;
    for(int i = 0; i < size_v; i++) {
        if(dynamic_array[i] != other_vector[i])
            return false;
    }
    return true;
}

template<typename data>
data& Vector_build<data>::operator[](int index) {
    return dynamic_array[index];
}

#endif