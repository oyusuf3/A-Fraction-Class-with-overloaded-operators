
#define FRACTION_H
#ifndef FRACTION_EXCEPTION_H
#define FRACTION_EXCEPTION_H

#include<iostream>
#include<exception>
#include <stdexcept>

using namespace std;

/*Exception class derived from std::exception*/
class FractionException : public exception
    {
        public:
            const char* what() const throw()
        {
 return "ZeroDivisionError";
             }
        };
#endif
