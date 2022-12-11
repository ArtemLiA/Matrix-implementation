//Artem Liakhov

#ifndef MATRIX_EXCEPTIONS
#define MATRIX_EXCEPTIONS

#include <exception>
#include <iostream>


class matrix_exception: public std::exception{
public:
    explicit matrix_exception(const char* message);
    explicit matrix_exception(std::string message);
    virtual const char* what() const noexcept;
protected:
    std::string msg_;
};

class init_matrix_exception: public matrix_exception{
public:
    explicit init_matrix_exception(const char* message);
    explicit init_matrix_exception(std::string message);
};

class operations_matrix_exception: public matrix_exception{
public:
    explicit operations_matrix_exception(const char* message);
    explicit operations_matrix_exception(std::string message);
};

matrix_exception::matrix_exception(const char *message): msg_(message) {}
matrix_exception::matrix_exception(std::string message): msg_(std::move(message)) {}
const char* matrix_exception::what() const noexcept{
    return msg_.c_str();
};


init_matrix_exception::init_matrix_exception(const char *message):matrix_exception(message){}
init_matrix_exception::init_matrix_exception(std::string message):matrix_exception(std::move(message)){}

operations_matrix_exception::operations_matrix_exception(const char *message): matrix_exception(message){}
operations_matrix_exception::operations_matrix_exception(std::string message):matrix_exception(std::move(message)){}

#endif