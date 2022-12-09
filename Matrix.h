//
// Liakhov Artem
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include "Array.h"
template<typename T>
class Matrix {
public:
    Array<Array<T>> mat_;
    size_t rows_;
    size_t columns_;
public:
    explicit Matrix(size_t m, size_t n = 1, T elems = T());
    //Matrix(std::initializer_list<std::initializer_list<T>> list);
    //~Matrix();
};

#include "Matrix.cpp"

#endif //MATRIX_MATRIX_H
