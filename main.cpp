//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<double> my_mat(2, 5);
    std::cout << my_mat << std::endl;
    Matrix<double> mat(4, 1, 3.1415);
    std::cout << mat;
    return 0;
}
