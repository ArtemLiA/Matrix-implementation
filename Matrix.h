//
// Liakhov Artem
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include "Array.h"


template<class T>
class Matrix {
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& arr);
public:
    Array<Array<T>> mat_;
    size_t rows_;
    size_t columns_;
public:
    explicit Matrix(size_t m_rows, size_t n_col = 1, T elems = T());
    Matrix(const Matrix<T>& other);
    template<class U> explicit Matrix(const Matrix<U>& other);
    template<class U> Matrix(std::initializer_list<U> list);
    template<class U> Matrix(std::initializer_list<std::initializer_list<U>> list);
    Matrix(Matrix<T>&& other) noexcept;
    //Const methods
    T at(int i, int j) const;
    //Operators overloading
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T> operator+(const Matrix<T>& other);
    Matrix<T> operator*(const Matrix<T>& other);

    T& operator ()(int i, int j);
};

#include "Matrix.cpp"
#endif //MATRIX_MATRIX_H
