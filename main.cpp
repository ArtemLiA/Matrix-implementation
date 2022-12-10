//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Array<int> arr1 = {1, 2, 2, 3};
    Array<int> arr2 = std::move(arr1);
    Array<int> arr3(arr1);
    std::cout << "arr1: " << arr1 << std::endl;
    std::cout << "arr2: " << arr2 << std::endl;
    std::cout << "arr3: " << arr3 << std::endl;
    return 0;
}
