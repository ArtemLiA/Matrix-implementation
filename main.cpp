//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<int> MyMatrix(3, 3, 12);
    for (int i = 0; i < 3; i++){
        std::cout << MyMatrix.mat_[i] << std::endl;
    }
    Matrix<int> NewMatrix = MyMatrix;
    NewMatrix.mat_[0][0] = 19;
    std::cout << "NewMatrix" << std::endl;
    for (int i = 0; i < 3; i++){
        std::cout << NewMatrix.mat_[i] << std::endl;
    }
    std::cout << "MyMatrix" << std::endl;
    for (int i = 0; i < 3; i++){
        std::cout << MyMatrix.mat_[i] << std::endl;
    }
    return 0;
}
