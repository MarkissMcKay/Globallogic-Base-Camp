/*
  file:	    Functions.h
  
  brief:    Defines function prototypes for Exerñise 28 from Task 3
 
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

uc NumberOfTheCombinations( char* str, char* combination ); // returns number of the symbol combinations, selected by user, which are present in the sentence, entered from keyboard  

unsigned short* Resize( unsigned short * a, uc newsize, uc oldsize ); // changes  size of the (unsigned short) massive 

void BiggestNumber( unsigned short* massOfNumbers, uc numberOfTheSentences, char* combination ); // searches and shows the sentence with biggest number of the symbol combinations, selected by user 

#endif /* _FUNCTIONS_H_ */