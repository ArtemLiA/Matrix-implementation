//
// Created by lyaho on 01.12.2022.
//

#ifndef MATRIX_ARRAY_H
#define MATRIX_ARRAY_H
#include <iostream>

typedef unsigned int uint;

template<class T>
class array {
private:
    T* start;
public:
    array();
    array(std::initializer_list<T>);
    ~array();
    void push_back(T value);
    void front();
    T &operator[](int i);
    uint size();
};

#include "array.cpp"
#endif //MATRIX_ARRAY_H
