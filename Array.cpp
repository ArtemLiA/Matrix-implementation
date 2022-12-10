//
// Created by lyaho on 04.12.2022.
//
#ifndef MATRIX_ARRAY_CPP
#define MATRIX_ARRAY_CPP
#include "Array.h"

//Constructors and destructor
template<class T> Array<T>::Array(size_t sz) {
    data_ = new T[sz + 10];
    allocated_ = sz + 10;
}


template<class T> Array<T>::Array(std::initializer_list<T> list) {
    size_t idx = 0;
    for (auto val: list){
        idx++;
    }
    data_ = new T[idx + 10];
    allocated_ = idx + 10;
    size_ = idx;
    idx = 0;
    try {
        for (auto val: list){
            data_[idx] = val;
            idx++;
        }
    }
    catch (...){
        delete [] data_;
        throw;
    }
}

template<class T>
Array<T>::Array(const Array<T> &other){
    data_ = new T[other.allocated_];
    allocated_ = other.allocated_;
    try{
        for (size_t i = 0; i < other.size_; i++){
            data_[i] = other.at(i);
        }
    }
    catch(...){
        delete [] data_;
        throw;
    }
    size_ = other.size_;
}

template<class T>
Array<T>::Array(Array<T> &&other) noexcept{
    data_ = other.data_;
    size_ = other.size_;
    allocated_ = other.allocated_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.allocated_ = 0;
}

template<class T>Array<T>::~Array(){
    delete [] data_;
    data_ = nullptr;
}

//Const methods
template<class T>
size_t Array<T>::capacity() const{
    return allocated_;
}

template<class T> T Array<T>::at(int idx) const {
    if (idx < 0 || idx >= size_){
        throw std::out_of_range("Array construct error");
    }
    return data_[idx];
}

template<class T>
size_t Array<T>::size() const{
    return size_;
}

//Not const methods
template<class T> void Array<T>::push_back(T val){
    if (size_ < allocated_){
        data_[size_] = val;
        size_++;
        return;
    }
    //Case size_ == allocated_
    this->resize(size_ + 1);
    data_[size_] = val;
    size_++;
}

template<class T>void Array<T>::resize(size_t n_sz){
    if (n_sz < size_){
        size_ = n_sz;
        return;
    }
    if (allocated_ >= n_sz){
        return;
    }
    T* new_data_ = new T[n_sz + 10];
    try{
        for (size_t idx = 0; idx < size_; idx++){
            new_data_[idx] = data_[idx];
        }
    }
    catch(...){
        delete [] new_data_;
        throw;
    }
    delete [] data_;
    data_ = new_data_;
    allocated_ = n_sz + 10;
}

//Operators overloading
template<class T>T& Array<T>::operator[](int idx) {
    if (idx < 0 || idx >= size_){
        throw std::out_of_range("index outside array");
    }
    return data_[idx];
}

template<class T> Array<T>& Array<T>::operator=(const Array<T> &other) {
    if (this == &other){
        return *this;
    }
    T* new_data = new T[other.allocated_];
    try{
        for (size_t idx = 0; idx < other.size_; idx++){
            new_data[idx] = other.at(idx);
        }
    }
    catch(...){
        delete [] new_data;
        throw;
    }
    delete [] data_; //Avoid memory leaks
    data_ = new_data;
    size_ = other.size_;
    allocated_ = other.allocated_;
}

template<class T>
Array<T>& Array<T>::operator=(Array<T> &&other) noexcept{
    if (this == &other){
        return *this;
    }
    data_ = other.data_;
    allocated_ = other.allocated_;
    size_ = other.size_;
    other.data_ = nullptr;
    other.allocated_ = 0;
    other.allocated_ = 0;
    return *this;
}

//Friend operators overloading
template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
    for (size_t idx = 0; idx < arr.size_; idx++){
        os << arr.data_[idx] << " ";
    }
    return os;
}







#endif //MATRIX_ARRAY_CPP