//Liakhov Artem

#ifndef MATRIX_MATRIX_CPP
#define MATRIX_MATRIX_CPP
#include "Matrix.h"
#include <iostream>

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

template<class U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& arr){
    for (size_t i = 0; i < arr.rows_; i++){
        os << arr.mat_.at(i) << std::endl;
    }
    return os;
}


#endif