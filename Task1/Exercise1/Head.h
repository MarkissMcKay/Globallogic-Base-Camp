/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 1 from Task 1
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H
#include <iostream>

unsigned long Function( unsigned long ); // returns the next even number which follows after some (unsigned long int) digit entered from keyboard

void ShowBinary( unsigned long ); // shows binary code of the digit, entered from keyboard

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise  

bool ReadULI( unsigned long & ); // function that reads (and convert to unsigned long int) symbols from keyboard

#endif /* _HEAD_H_ */