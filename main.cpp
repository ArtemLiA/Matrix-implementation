//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Array.h"

int main(){
    Array<int> my_arr = {1, -2, 3, 7, 8};
    std::cout << my_arr.capacity() << std::endl;
    my_arr.resize(2);
    std::cout << my_arr << std::endl;
    std::cout << my_arr.capacity() << std::endl;
    return 0;
}
