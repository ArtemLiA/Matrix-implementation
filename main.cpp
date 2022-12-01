#include <iostream>
#include "array.h"

int main() {
    array<int> my_arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    try{
        for (int i = 0; i < my_arr.size(); i++){
            std::cout << my_arr[i] << " ";
        }
        std::cout << "size=" << my_arr.size();
    }
    catch (int error){
        if (error == 1){
            std::cout << "Index outside the array";
        }
    }
    std::cout << std::endl;
    return 0;
}
