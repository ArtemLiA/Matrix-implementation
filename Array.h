//
// Created by lyaho on 04.12.2022.
//

#ifndef MATRIX_ARRAY_H
#define MATRIX_ARRAY_H
#include <iostream>
#include <exception>
template<class T> class Array {
    //friend operators overloading
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Array<U>& arr);
public:
    //Constructors and destructor
    explicit Array(size_t sz = 0);
    Array(std::initializer_list<T> list);
    Array(const Array<T>& other);
    ~Array();

    //Const methods
    size_t capacity() const;
    T at(int idx) const;
    size_t size() const;

    //Not const methods
    void push_back(T val);
    void resize(size_t n_sz);

    //Operators overloading
    T& operator[](int idx);
    Array& operator=(const Array<T>& other);
protected:
    T* data_;
    size_t allocated_, size_ = 0;
};

#include "Array.cpp"
#endif //MATRIX_ARRAY_H
