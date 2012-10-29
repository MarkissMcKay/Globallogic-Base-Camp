/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 18 from Task 1
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>

bool Function( unsigned long );  // returns 1 in case both of two any "side-by-side" bits in some (unsigned long int) digit, entered from keyboard are equal to 1, and 0 otherwise!

void ShowBinary( unsigned long ); // shows binary code of the digit, entered from keyboard

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise   

bool ReadULI( unsigned long & ); // function that reads (and convert to unsigned long int) symbols from keyboard

#endif /* _HEAD_H_ */