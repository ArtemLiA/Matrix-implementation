//
// Created by lyaho on 04.12.2022.
//
#ifndef MATRIX_ARRAY_CPP
#define MATRIX_ARRAY_CPP
#include "Array.h"

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

template<class T> T Array<T>::at(int idx) {
    if (idx < 0 || idx >= size_){
        throw std::out_of_range("Array construct error");
    }
    return data_[idx];
}


template<class T>Array<T>::~Array() noexcept{
    delete [] data_;
}

template<class T>void Array<T>::resize(size_t n_sz){
    T* new_data_ = new T[n_sz + 10];
    try{
        for (size_t idx = 0; idx < n_sz && idx < size_; idx++){
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
    if (n_sz < size_){
        size_ = n_sz;
        return;
    }
}

template<class T> void Array<T>::push_back(T val){
    if (size_ < allocated_){
        data_[size_] = val;
        size_++;
        return;
        //В случае исключения здесь состояние объекта не изменится -> всё ок.
    }
    //Case size_ == allocated_
    this->resize(size_ + 1); //Если здесь вылетело исключение, то исходный объект не изменится
    data_[size_] = val; //Если здесь вылетает исключение, то всё в порядке. (выделенной памяти станет больше)
    size_++;
}

template<class T>T& Array<T>::operator[](int idx) {
    if (idx < 0 || idx >= size_){
        throw std::out_of_range("index outside array");
    }
    return data_[idx]; //С исключениями всё ок
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr){
    os << " ";
    for (size_t idx = 0; idx < arr.size_; idx++){
        os << arr.data_[idx] << " ";
    }
    return os;
}

template<class T>
size_t Array<T>::size() {
    return size_;
}

template<class T>
size_t Array<T>::capacity() {
    return allocated_;
}



#endif //MATRIX_ARRAY_CPP