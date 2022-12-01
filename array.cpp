//
// Created by lyaho on 01.12.2022.
//

#ifndef MATRIX_ARRAY_CPP
#define MATRIX_ARRAY_CPP
#include <iostream>
#include "array.h"

template<class T>
array<T>::array() {
    data_ = new T[10]; //Allocate memory for 10 new elements
    size_ = 0;
    allocated_ = 10;
}

template<class T>
array<T>::array(std::initializer_list<T> lst) {
    size_ = 0;
    allocated_ = 0;
    for (auto val:lst){
        allocated_ += 1;
    };
    data_ = new T[allocated_ + 10];
    for (auto val:lst){
        this->push_back(val);
    }
}

template<class T>
void array<T>::push_back(T value) {
    if (size_ < allocated_){
        data_[size_] = value;
        size_++;
        return;
    }
    T* new_array = nullptr;
    new_array = new T[allocated_ + 10];
    for (size_t i = 0; i < size_; i++){
        new_array[i] = data_[i];
    }
    new_array[size_] = value;
    T* temp = data_;
    data_ = new_array;
    allocated_ += 10;
    size_++;
    delete temp;
}

template<class T>
array<T>::~array() {
    allocated_ = 0;
    size_ = 0;
    delete data_;
    data_ = nullptr;
}

template<class T>
size_t array<T>::size() {
    return size_;
}

template<class T>
T& array<T>::operator[](int i) {
    int error_code = 0;
    if (i < 0 || i >= size_){
        throw 1;
    }
    return data_[i];
}


#endif //MATRIX_ARRAY_CPP
