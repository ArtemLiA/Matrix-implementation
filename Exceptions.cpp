//
// Created by lyaho on 04.12.2022.
//
#ifndef MATRIX_EXCEPTIONS
#define MATRIX_EXCEPTIONS
#include <stdexcept>

class RowException: public std::exception{
public:
    explicit RowException(const char* message);
    explicit RowException(std::string message);
    virtual const char* what() const noexcept;
protected:
    std::string mes_;
};

class MemoryRowException: public RowException{
public:
    explicit MemoryRowException(const char* message);
    explicit MemoryRowException(std::string message);
};

class OutOfRange: public RowException{
public:
    explicit OutOfRange(const char* message);
    explicit OutOfRange(std::string message);
};

//Implementation of exceptions
RowException::RowException(const char *message):mes_(message) {}
RowException::RowException(std::string message):mes_(std::move(message)){}
const char* RowException::what() const noexcept {return mes_;}

MemoryRowException::MemoryRowException(const char *message): RowException(message) {}
MemoryRowException::MemoryRowException(std::string message): RowException(message) {}

OutOfRange::OutOfRange(const char *message): RowException(message) {}
OutOfRange::OutOfRange(std::string message): RowException(message) {}



#endif //MATRIX_EXCEPTIONS