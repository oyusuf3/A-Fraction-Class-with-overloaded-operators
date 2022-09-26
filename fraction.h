//* 
   File:        Fraction.h
   Author:      P Kraft
   Description: Header file for class Fraction
*/

#ifndef FRACTION_H
#define FRACTION_H

#include <cstdlib>  // stdlib.h for C++
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Fraction  {

   // Overloaded stream insertion and extraction operators
   friend ostream& operator<<(ostream&, const Fraction&);
   friend istream& operator>>(istream&, Fraction&);

   public:
      Fraction(int,int=1);       // constructor; first arg is for numerator, second arg is for denominator
                                 // Fraction(int) should default denominator to 1
      Fraction();                // constructor; set value to 0

      void setNumbers(int,int);
      float getFloat(void);

      // Overloaded assignment operator
      Fraction& operator=(const Fraction &);

      // Overloaded relational operators
      int operator==(const Fraction &) const;
      int operator!=(const Fraction &) const;
      int operator>(const Fraction &) const;
      int operator>=(const Fraction &) const;
      int operator<(const Fraction &) const;
      int operator<=(const Fraction &) const;

      // Overloaded arithmetic operators
      Fraction operator+(const Fraction &);
      Fraction operator-(const Fraction &);
      Fraction operator*(const Fraction &);
      Fraction operator/(const Fraction &);
      Fraction& operator+=(const Fraction &);
      Fraction& operator-=(const Fraction &);
      Fraction& operator*=(const Fraction &);
      Fraction& operator/=(const Fraction &); 

   private:
      void reduceFraction();
      int num,den;
};

#endif

//  *****   END OF FILE fraction.H   *****