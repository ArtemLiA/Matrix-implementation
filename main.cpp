#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<int> mat1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix<float> mat2 = {{1.5, 2.3, 3.}, {3., 4., 5.}, {6., 7., 10.}};
    mat2 *= mat2;
    std::cout << mat2;
    return 0;
}
