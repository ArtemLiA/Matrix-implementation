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
    ~array() noexcept;
    void push_back(T value);
    void insert(T value);
    T front();
    T back();
    bool empty();
    size_t size();
    size_t capacity();
    T &operator[](int i);
};

#include "array.cpp"
#endif //MATRIX_ARRAY_H
