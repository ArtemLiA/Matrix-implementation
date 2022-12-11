//Liakhov Artem

#ifndef MATRIX_MATRIX_CPP
#define MATRIX_MATRIX_CPP
#include "Matrix.h"
#include <iostream>
#include <iterator>

template<class T>
Matrix<T>::Matrix(size_t m_rows, size_t n_col, T elems) {
    rows_ = m_rows;
    columns_ = n_col;
    Array<T> buf_arr(n_col);
    for (size_t i = 0; i < n_col; i++){
        buf_arr.push_back(elems);
    }
    for (size_t j = 0; j < m_rows; j++){
        mat_.push_back(buf_arr);
    }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T> &other) {
    mat_ = other.mat_;
    rows_ = other.rows_;
    columns_ = other.columns_;
}

template<class T>
Matrix<T>::Matrix(Matrix<T> &&other) noexcept {
    mat_ = std::move(other.mat_);
    rows_ = other.rows_;
    columns_ = other.columns_;
    other.rows_ = 0;
    other.columns_ = 0;
}

template<class T> template<class U>
Matrix<T>::Matrix(const Matrix<U> &other) {
    Array<T> buffer(other.columns_);
    for (size_t i = 0; i < other.rows_; i++){
        for (size_t j = 0; j < other.columns_; j++){
            buffer.push_back(static_cast<T>(other.at(i, j)));
        }
        mat_.push_back(buffer);
        buffer.resize(0);
    }
    rows_ = other.rows_;
    columns_ = other.columns_;
}

template<class U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& arr){
    for (size_t i = 0; i < arr.rows_; i++){
        os << arr.mat_.at(i) << std::endl;
    }
    return os;
}

template<class T> template<class U>
Matrix<T>::Matrix(std::initializer_list<U> list) {
    Array<T> buffer_list;
    columns_ = 0;
    for (auto val: list){
        buffer_list.push_back(static_cast<T>(val));
        columns_++;
    }
    mat_.push_back(buffer_list);
    rows_ = 1;
}

template<class T>
T Matrix<T>::at(int i, int j) const {
    if (i < 0 || i >= rows_){
        throw std::out_of_range("index i outside Matrix");
    }
    if (j < 0 || j >= columns_){
        throw std::out_of_range("index j outside Matrix");
    }
    return mat_.at(i).at(j);
}

template<class T> template<class U>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<U>> list){
    //Check sizes
    auto iter = list.begin();
    while (iter != list.end()) {
        if (iter->size() != list.begin()->size()) {
            throw std::out_of_range("list size inconsistencies");
        }
        ++iter;
    }
    Array<T> buffer_list;
    for (auto lst: list){
        for (auto val: lst){
            buffer_list.push_back(static_cast<T>(val));
        }
        mat_.push_back(buffer_list);
        buffer_list.resize(0);
    }
    rows_ = list.size();
    columns_ = list.begin()->size();
}

//Operators overloading
template<class T>
T& Matrix<T>::operator()(int i, int j) {
    if (i < 0 || i >= rows_){
        throw std::out_of_range("index i outside Matrix");
    }
    if (j < 0 || j >= columns_){
        throw std::out_of_range("index j outside Matrix");
    }
    return mat_[i][j];
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other){
    if (this == &other){
        return *this;
    }
    mat_ = other.mat_;
    rows_ = other.rows_;
    columns_ = other.columns_;
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other){
    if (rows_ != other.rows_ || columns_ != other.columns_){
        throw std::out_of_range("matrix size inconsistency");
    }
    Matrix<T> result(rows_, columns_);
    for (size_t i = 0; i < rows_; i++){
        for (size_t j = 0; j < columns_; j++){
            result(i, j) = this->at(i, j) + other.at(i, j);
        }
    }
    return result;
}



#endif