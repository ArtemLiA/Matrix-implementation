//Идеи и концепты при реализации:
//Реализовать свой класс Array
//На основе класса Array реализовать класс Matrix
//В ходе реализации каждого из классов обеспечить строгую безопасность при работе с исключениями
//Дополнительно для лучшей производительности реализовать конструктор перемещения

#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Array<int> my_arr = {1, -2, 3, 7, 8};
    std::cout << my_arr.capacity() << std::endl;
    for (int i = 0; i < 11; i++){
        my_arr.push_back(2*i + 1);
    }
    std::cout << my_arr << std::endl;
    std::cout << my_arr.capacity() << std::endl;

    Array<int> new_arr(std::move(my_arr));
    std::cout << "new_arr:"<< new_arr.size() << std::endl;
    std::cout << "my_arr:" << my_arr.size() << std::endl;
    my_arr.push_back(156);
    std::cout << my_arr << std::endl;
    std::cout << my_arr.capacity() << std::endl;
    std::cout << my_arr.size() << std::endl;
    return 0;
}
