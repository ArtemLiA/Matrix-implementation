//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<double> my_mat = {{1.2, 2.2, 2.4}, {3.5, 5.6, 4.8}, {1.0, 2.0, 3.5}};
    std::cout << my_mat;
    Matrix<int>new_mat(my_mat);
    new_mat(0, 0) = 3;
    std::cout << std::endl << "New Matrix:\n" << new_mat;
    return 0;
}
