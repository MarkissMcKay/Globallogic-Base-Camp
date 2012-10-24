/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 11 from Task 1
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>

unsigned short Function( unsigned long ); // returns position of the "yangest" nonzero bit in some (unsigned long int) digit, entered from keyboard

void ShowBinary( unsigned long ); // shows binary code of the digit, entered from keyboard

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise  

bool ReadULI( unsigned long & ); // function that reads (and convert to unsigned long int) symbols from keyboard

#endif