/*
  file:	    Functions.h
  
  brief:    Defines function prototypes for Exerñise 3 from Task 3
 
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

char* Func( char* str, char* symbol, uc & length, uc & startPoint); // returns pointer on the end of the word in the sentence entered from keyboard, which contains the symbol selected by user

void Sstring(char * str, uc length); // shows the word in the sentence entered from keyboard, which contains the symbol selected by user

#endif /* _FUNCTIONS_H_ */