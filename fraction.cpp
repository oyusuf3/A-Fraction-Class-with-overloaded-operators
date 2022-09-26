
#include "fraction.h"
#include "fraction_exception.h"
#define FRACTION_H
#define FRACTION_EXCEPTION_H
#include <iostream>
#include <stdexcept>
using namespace std;
//set the number the fraction
void Fraction::setNumbers(int value1, int value2) {
	this->num = value1;
	this->den = value2;
	if(this->den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
}


//get a float value of a fraction
float Fraction::getFloat(){
    if(this->den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
	return ((float)this->num/(float)this->den);
		
}
//constructor of fraction that makes it num 0 and den 1
Fraction::Fraction()
{ 
  num = 0;
  den = 1;
    this->reduceFraction();
}
//give the num and den values to a fraction
Fraction :: Fraction(int x,int y)
{
    num=x;
    den=y;
    this->reduceFraction();
    if(den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
}
//gives the values of a fraction to a new fraction
Fraction& Fraction::operator=(const Fraction &obj){

    num = obj.num;
    den = obj.den;
    this->reduceFraction();
   
    if(this->den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
     return *this;
}
//simplifies the fraction
void Fraction :: reduceFraction(){
    if(den < 0){
    num = num * -1;
    den = den * -1;
    }
     if(this->den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
    
    
    for (int i = 1; i <=  den; i++) {
    if (num % i == 0 && den % i ==0) {
      num = num/i;
      den = den/i;
    }
    }
    for (int i = 1; i <=  den; i++) {
    if (num % i == 0 && den % i ==0) {
      num = num/i;
      den = den/i;
    }
   
    }
 
}

//giving input values to the later put in the fractions
istream &operator >> (istream &in , Fraction &obj){
    cout<<"enter numinator : ";
    in>>obj.num;
    cout<<"enter dominator : ";
    in>>obj.den;
    if(obj.den == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
    obj.reduceFraction();
    return in;
   
}
//puts the input value into the fractions
 ostream &operator << (ostream &out , const Fraction &obj){
   if (obj.num==0)
        out<<0<<endl;
    else if (obj.den==obj.num)
        out<<1<<endl;
    else if (obj.den==1)
        out<<obj.num<<endl;
    else
        out<<obj.num<<'/'<<obj.den;
    return out;
}

//add fractions together
Fraction Fraction::operator+(const Fraction  &obj)
{
    if(this->den == obj.den){
         Fraction frac(this->num + obj.num,obj.den);
          frac.reduceFraction();
         return frac;
    }
   Fraction frac((this->num * obj.den) + (this->den * obj.num),(this->den * obj.den));
    frac.reduceFraction();
	return frac;
}
//subtract fractions from one another
Fraction Fraction::operator-(const Fraction  &obj)
{
    if(this->den == obj.den){
         Fraction frac(this->num - obj.num,obj.den);
          frac.reduceFraction();
         return frac;
    }
   Fraction frac((this->num * obj.den) - (this->den * obj.num),(this->den * obj.den));
    frac.reduceFraction();
	return frac;
}
//multiplies fractions together
Fraction Fraction::operator*(const Fraction  &obj)
{
    Fraction frac;

	frac.num = this->num * obj.num;
	frac.den = this->den * obj.den;
	frac.reduceFraction();
	
	return frac;
}

//divides fraction together
Fraction Fraction::operator/(const Fraction  &obj)
{
    
    Fraction frac((this->num * obj.den),(this->den * obj.num ));
    frac.reduceFraction();
    if((this->den * obj.num) == 0){
     throw FractionException();//Throw division by zero exception 
        
    }
	return frac;
   
}
//checks if fraction equals each other
int Fraction::operator== (const Fraction &obj)const{
    return (this->num == obj.num  &&  this->den == obj.den);
}
//check if Fraction dont equal each other
int Fraction::operator!=(const Fraction &obj)const{
	return (this->num != obj.num || this->den != obj.den);
}
//sees if a fraction is greater than another fraction
int Fraction::operator>(const Fraction &obj)const{
	return ((this->num * obj.den) > (this->den * obj.num));
}
//checks if the fraction is greater than or equal than another fraction
int Fraction::operator>=(const Fraction &obj)const{
    
	return ((this->num * obj.den) >= (this->den * obj.num));
}
//sees if a fraction is less than another fraction
int Fraction::operator<(const Fraction &obj)const{
	return ((this->num * obj.den) < (this->den * obj.num));
}
//checks if the fraction is less than or equal than another fraction
int Fraction::operator<=(const Fraction &obj)const{
    return ((this->num * obj.den) <= (this->den * obj.num));
    
}
//uses additonal assingment to add to the fraction and keep the value
Fraction & Fraction :: operator+=(const Fraction& obj){

        
          *this = *this + obj;
          reduceFraction();
        return *this;
        
    
}
//uses to subtract value to the fraction and keeps it
Fraction & Fraction :: operator-=(const Fraction &obj){
        *this = *this - obj;
          reduceFraction();
        return *this;
}
//uses to multiply value to the fraction and keeps it
Fraction & Fraction :: operator*=(const Fraction &obj){
  
	*this = *this * obj;
          reduceFraction();
        return *this;
}
//uses to divide value to the fraction and keeps it
Fraction & Fraction :: operator/=(const Fraction &obj){
	*this = *this / obj;
          reduceFraction();
          
        return *this;
}