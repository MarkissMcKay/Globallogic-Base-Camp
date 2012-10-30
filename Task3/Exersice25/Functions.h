/*
  file:	    Functions.h
  
  brief:    Defines function prototypes for Exerñise 25 from Task 3
 
  autor:    Shalai Markiian
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <memory.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

typedef unsigned char uc;

char* Func( char* str, uc & length, uc & startPoint); // returns pointer on the end of the word in the sentence entered from keyboard

void Sstring( char * str, uc length, char* reverseStr, char* sTemp, bool & firstLanch ); // creates sentence with reverse words order using a sentence entered from keyboard

#endif /* _FUNCTIONS_H_ */