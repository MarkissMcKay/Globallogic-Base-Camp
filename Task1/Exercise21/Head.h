/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 21 from Task 1
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>

signed short Function( signed long ); // returns some (signed long) number in case its negative and 0 otherwise

void ShowBinary( signed long ); // shows binary code of the digit, entered from keyboard

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise 

bool ReadSLI( signed long & ); // function that reads (and convert to signed long int) symbols from keyboard

#endif /* _HEAD_H_ */