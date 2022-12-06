cmake_minimum_required(VERSION 3.23)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_executable(Matrix main.cpp Exceptions.cpp Array.cpp Array.h Matrix.cpp Matrix.h)
