//
// Liakhov Artem
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include "Array.h"


template<class T>
class Matrix {
    //Operator <<
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& arr);
    //Operator *: mat * val (same type)
    template<class U>
    friend Matrix<U> operator*(const Matrix<U>& mat, U val);
    //Operator *: val * mat (same type)
    template<class U>
    friend Matrix<U> operator*(U val, const Matrix<U>& mat);
    //Operator- (same type)
    template<class U>
    friend Matrix<U> operator-(const Matrix<U>& left, const Matrix<U>& right);
    //Operator const * mat (different type)
    template<class V, class U>
    friend Matrix<V> operator*(const Matrix<V>& mat, U val);
    //Operator mat * const (different type)
    template<class V, class U>
    friend Matrix<V> operator*(U val, const Matrix<V>& mat);
    //Operator - (different type)
    template<class V, class U>
    friend Matrix<V> operator-(const Matrix<V>& left, const Matrix<U>& right);
protected:
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
    size_t rows() const noexcept;
    size_t columns() const noexcept;
    Matrix<T> transpose();

    //Operators overloading
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T> operator+(const Matrix<T>& other);
    Matrix<T> operator*(const Matrix<T>& other);

    template<class U> Matrix<T>& operator=(const Matrix<U>& other);
    template<class U> Matrix<T> operator+(const Matrix<U>& other);
    template<class U> Matrix<T> operator*(const Matrix<U>& other);

    T& operator ()(int i, int j);
};

#include "Matrix.cpp"

#endif //MATRIX_MATRIX_H
