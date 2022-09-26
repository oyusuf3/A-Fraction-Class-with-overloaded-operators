#include <iostream>
#include "fraction.h"
#include "fraction_exception.h"
#include<exception>
#define FRACTION_H
#define FRACTION_EXCEPTION_H
using namespace std;
#include <stdexcept>

int main(){
     try{
    Fraction fraction1;
    Fraction fraction2;
    Fraction fraction3;
    
  cout<<"Enter a numerator and denominator for two fractions"<<endl;
  cin>> fraction1;
  cin>> fraction2;
  
     

   
  cout<<"The Fraction you have submitted first equals: "<<fraction1<<endl;
  cout<<"The Fraction you have submitted second equals: "<<fraction2<<endl;
  cout<<"The first Fraction you have submitted float equals: "<<fraction1.getFloat()<<endl;
  cout<<"The second Fraction you have submitted float equals: "<<fraction2.getFloat()<<endl;
   
   //made a 3rd fraction which is equal to the first fraction
   fraction3.operator=(fraction1);
   cout<<"made a copy of the first fraction: "<<fraction3<<endl;
   
   cout<< "if the first and second fraction equal each other itll result in one but  if not itll give zero: "<<fraction1.operator==(fraction2)<<endl;
   cout<< "if the first and second fraction equal each other itll result in zero but  if not itll give one: "<<fraction1.operator!=(fraction2)<<endl;
   cout<< "if the first is greater than or equal to the second fraction itll result 1 otherwise itll be zero: "<<fraction1.operator>=(fraction2)<<endl;
   cout<< "if the first is less than or equal to the second fraction itll result 1 otherwise itll be zero: "<<fraction1.operator<=(fraction2)<<endl;
   cout<< "if the first is greater than  the second fraction itll result 1 otherwise itll be zero: "<<fraction1.operator>(fraction2)<<endl;
   cout<< "if the first is less than  the second fraction itll result 1 otherwise itll be zero: "<<fraction1.operator<(fraction2)<<endl;
   
   cout<<"The addition of the two fraction is "<<fraction1.operator+(fraction2)<<endl;
   cout<<"The subtraction of the two fraction is "<<fraction1.operator-(fraction2)<<endl;
   cout<<"The multiplication of the two fraction is "<<fraction1.operator*(fraction2)<<endl;
   cout<<"The division of the two fraction is "<<fraction1.operator/(fraction2)<<endl;
   
   
    cout<<"The addition of the two fraction is "<<fraction1.operator+=(fraction2)<<endl;
    //the fraction1 now equals fraction1 plus fraction2
    cout<<"The Fraction you have submitted first equals: "<<fraction1<<endl;
   
   
    cout<<"The subtraction of the two fraction is "<<fraction1.operator-=(fraction2)<<endl;
    //the fraction 1 now equals fraction1 subtrated by fraction 2
    cout<<"The Fraction you have submitted first equals: "<<fraction1<<endl;
     
     
     
     cout<<"The multiplication of the two fraction is "<<fraction1.operator*=(fraction2)<<endl;
     //the fraction 1 now equals fraction1 multiplied by fraction 2
      cout<<"The Fraction you have submitted first equals: "<<fraction1<<endl;
      
      
      cout<<"The division of the two fraction is "<<fraction3.operator/=(fraction2)<<endl;
    //the fraction 1 now equals fraction1 divided by fraction2
    cout<<"The Fraction you have submitted first equals: "<<fraction1<<endl;
   
   
   

  
       
        
        
        
        
        
        
    
    
    
    
    
     }
    catch( FractionException e ) {
	cerr << "ZeroDivisonError" << endl;
}
catch(...) {
	cerr << "Incorrect Exception" << endl;
}


    return 0;
}