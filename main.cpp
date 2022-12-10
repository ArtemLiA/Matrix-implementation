//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Array<int> my_arr = {1, 2, 3, -8, 3};
    Array<int> my_arr_2 = std::move(my_arr);
    Array<int> my_arr_3 = std::move(my_arr);
    std::cout << "my_arr_3: " << my_arr_3 << std::endl;
    std::cout << "my_arr_2: " << my_arr_2 << std::endl;
    std::cout << "my_arr: " << my_arr << std::endl;
    my_arr.push_back(5);
    std::cout << "my_arr (after push):" << my_arr << std::endl;
    return 0;
}
