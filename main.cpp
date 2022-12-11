#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){
    Matrix<float> m1(4);
    Matrix<float> m2(4, 6);
    std::cout << "m1 matrix:\n" << m1;
    std::cout << "m2 matrix:\n" << m2;
    Matrix<int> m5 = { {1, 2, 3}, {4, 5, 6} };
    Matrix<int> m6 = { {1, 2, 3, 4, 5, 6}};
    Matrix<int> m7 = {1, 2, 3, 4, 5, 6};
    Matrix<int> m8 = {{1}, {2}, {3}, {4}, {5}, {6}};
    std::cout << "m5 matrix:\n" << m5 ;
    std::cout << "m6 matrix:\n" << m6;
    std::cout << "m7 matrix:\n" << m7;
    std::cout << "m8 matrix:\n" << m8;
    std::cout << std::endl;

    Matrix<float>m3(m1);
    std::cout << "m3 matrix:\n" << m3;
    std::cout << std::endl;

    m1 = m2;
    std::cout << "m1 matrix:\n" << m1;
    std::cout << std::endl;

    Matrix<float>m4(std::move(m2));
    std::cout << "m4 matrix:\n" << m4;
    std::cout << "m2 matrix (after moving):\n" << m2; //Only to show working move constructor
    std::cout << std::endl;

    Matrix<int> m = {{1, 2, 3}, {4, 5, 6}};
    std::cout << "m matrix:\n" << m;
    int val = m(0, 2);
    m(0, 2) = 7;
    std::cout << "val = " << val << std::endl;
    std::cout << "m matrix (after changing):\n" << m;
    std::cout << std::endl;

    Matrix<double> mat1 = {{1.2, -3.4, 5.2}, {7.8, 3.3, -3.14}, {7.9, -123.2, 3.4}};
    Matrix<double> mat2 = {{0.8, -7.97, 3.44}, {3.78, -16.7, 0.01}, {0.2, -0.7, 0.3}};
    Matrix<double> mat3 = {0.1, 0.2, 0.3};
    std::cout << "(mat1 + mat2):\n" << mat1 + mat2;
    std::cout << "(mat1 - mat2):\n" << mat1 - mat2;
    std::cout << "(mat1 * mat2):\n" << mat1 * mat2;
    std::cout << "(2.71 * mat1):\n" << 2.71 * mat1;
    std::cout << "(mat1 * 2.71):\n" << mat1 * 2.71;
    std::cout << std::endl;

    mat1 += mat2;
    std::cout << "mat1:\n" << mat1;
    mat1 -= mat2;
    std::cout << "mat2:\n" << mat2;
    mat3 *= mat1;
    std::cout << "mat3:\n" << mat3;
    std::cout << std::endl;

    try{
        std::cout << mat2 * mat3;
    }
    catch (std::out_of_range exp){
        std::cout << exp.what() << std::endl;
    }
    catch(...){
        std::cout << "Another exception" << std::endl;
    }

    Matrix<double> m_d = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int> m_i = { {1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}};
    Matrix<short> m_s = m_d;
    std::cout << "m_d matrix:\n" << m_d;
    std::cout << "m_i matrix:\n" << m_i;
    std::cout << "m_s matrix:\n" << m_s;
    m_s = m_i;
    std::cout << "(m_s = m_i):\n" << m_s;
    m_s -= m_i;
    std::cout << "(m_s -= m_i):\n" << m_s;
    m_s *= 3.14;
    std::cout << "(m_s *= 3.14):\n" << m_s;
    std::cout << "(m_s + m_i - m_s):\n" << m_s + m_i - m_s;
    Matrix<double> my_mat = m_d;
    Matrix<double> my_mat2 = m_i;
    std::cout << "(m_d * m_i):\n" << (my_mat *= my_mat2);
    std::cout << "(m_d * 0):\n" << m_d * 0;
    std::cout << "(3.14 * m_i):\n" << 3.14 * m_i;
    return 0;
}
