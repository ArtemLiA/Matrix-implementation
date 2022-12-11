//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<float> mat1 = {-1.1, -2.2, 3.3};
    Matrix<int> mat2 = {{2}, {3}, {4}};
    Matrix<int> mat3 = {1, 2, 3};
    Matrix<int> mat4(4*mat1);
    std::cout << mat3 - mat4 << "Next:" << std::endl;
    std::cout << mat4;
    return 0;
}
