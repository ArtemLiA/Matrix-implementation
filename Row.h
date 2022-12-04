//
// Created by lyaho on 04.12.2022.
//

#ifndef MATRIX_ROW_H
#define MATRIX_ROW_H
#include <iostream>

template<class T>
class Row {
    void reallocate(size_t n_sz);
public:
    explicit Row(size_t sz = 0);
    Row(std::initializer_list<T> list);
    ~Row();
    T at(size_t idx);
    void push_back(T val);
    T& operator[](size_t idx);
protected:
    T* data_;
    size_t allocated_, size_ = 0;
};

#include "Row.cpp"
#endif //MATRIX_ROW_H
