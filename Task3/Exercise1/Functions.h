/*
  file:	    Functions.h
  
  brief:    Defines function prototypes for Exerñise 1 from Task 3
 
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

char* Func( char* str, uc & length ); // returns pointer on the end of the longest word in the sentence, entered from keyboard

void Sstring(char * str, uc length); // shows the longest word in the sentence entered from keyboard

#endif /* _FUNCTIONS_H_ */