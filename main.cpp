//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<int> My_Matrix(1, 2, 3);
    Matrix<int> New_Matrix(std::move(My_Matrix));
    std::cout << "New Matrix: " << New_Matrix;
    std::cout << "Old Matrix: " << My_Matrix;
    return 0;
}
