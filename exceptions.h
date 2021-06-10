#ifndef LAB03_EXCEPTIONS_H
#define LAB03_EXCEPTIONS_H

#include <exception>
#include <cstdlib>
#include <string>

class indexOutOfRange : public std::exception {
public:
    const char * what() const noexcept override{
        return "Invalid index!";
    }

};

class invalidArgument : public std::exception {
public:
    const char * what() const noexcept override{
        return "Bad argument!";
    }
};

#endif //LAB03_EXCEPTIONS_H
