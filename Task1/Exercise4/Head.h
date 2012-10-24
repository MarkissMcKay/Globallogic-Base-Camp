/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 4 from Task 1
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>

unsigned long Function( unsigned long ,short , short ); // changes positions of two bits, selected by the user, in some (unsigned long int) digit, entered from keyboard

unsigned long HelpFunction( unsigned long ,short , short ); // returns 1 in case two bits, selected by the user, in some (unsigned long int) digit are equal and 0 otherwise!

void ShowBinary( unsigned long ); // shows binary code of the digit, entered from keyboard

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise 

bool ReadULI( unsigned long & ); // function that reads (and convert to unsigned long int) symbols from keyboard

bool ReadShort( unsigned short & ); // function that reads (and convert to unsigned short int) symbols from keyboard
 
#endif /* _HEAD_H_ */