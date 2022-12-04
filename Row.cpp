//
// Created by lyaho on 04.12.2022.
//

#ifndef MATRIX_ROW_CPP
#define MATRIX_ROW_CPP
#include "Row.h"
#include "Exceptions.cpp"

template<class T> Row<T>::Row(size_t sz) {
    try{
        new T[sz+10];
    }
    catch (...){
        data_ = nullptr;
        allocated_ = 0;
        size_ = 0;
        throw MemoryRowException("Construct error");
    }
    size_ = sz;
    allocated_ = sz + 10;
}


template<class T> Row<T>::Row(std::initializer_list<T> list){
    size_ = 0;
    for (auto val:list){
        size_++;
    }
    try{
        data_ = new T[size_ + 10];
    }
    catch(...){
        throw MemoryRowException("Construct error");
    }
    allocated_ = size_ + 10;
    for (size_t idx = 0; idx < size_; idx++){
        try{
            data_[idx] = list[idx];
        }
        catch (...){
            delete data_; //Avoid memory leaks
            throw MemoryRowException("Construct error");
        }
    }
}



#endif //MATRIX_ROW_CPP
