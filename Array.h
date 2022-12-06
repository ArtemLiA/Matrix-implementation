//
// Created by lyaho on 04.12.2022.
//

#ifndef MATRIX_ARRAY_H
#define MATRIX_ARRAY_H
#include <iostream>
#include <exception>
template<class T> class Array {
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
public:
    explicit Array(size_t sz = 0);
    Array(std::initializer_list<T> list);
    Array(const Array<T>& other);
    ~Array();
    T at(int idx) const;
    void push_back(T val);
    void resize(size_t n_sz);
    T& operator[](int idx);
    size_t capacity();
    size_t size();
    Array& operator=(const Array<T>& other);
protected:
    T* data_;
    size_t allocated_, size_ = 0;
};

#include "Array.cpp"
#endif //MATRIX_ARRAY_H
