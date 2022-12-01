//Liakhov Artem

#ifndef MATRIX_ARRAY_H
#define MATRIX_ARRAY_H
#include <iostream>


template<class T>
class array {
private:
    T* data_;
    size_t allocated_;
    size_t size_;
public:
    array();
    array(std::initializer_list<T> lst);
    ~array();
    void push_back(T value);
    void front();
    T &operator[](int i);
    size_t size();
};

#include "array.cpp"
#endif //MATRIX_ARRAY_H
