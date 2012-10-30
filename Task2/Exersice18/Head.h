/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 18 from Task 2
 
  autor:    Shalai Markiian
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <memory.h>
#include <stdlib.h>
#include <cstdlib>


struct Factory 
{
	unsigned short dayNumber;
	
	unsigned short plan;
	
	unsigned short actualyDone;
	
	double percentage;
};


char* Days( unsigned short ); // returns the name of the day according to its number (income parameter)

void Function( struct Factory*, unsigned long ); // sorts the items of the massive of the structs according to the percentage of the plan

bool IsDigit( char* ); // function: returns false in case string it takes is digit, and true otherwise 

char ReadDigit( unsigned short & ); // function that reads (and convert to digit) symbols from keyboard

bool ReadStruct( struct Factory*, unsigned long ); // fill the struct's fields with some values

void PrintStruct( struct Factory*, unsigned long ); // prints the fild's values of the structs

struct Factory * Resize( struct Factory*, int, int ); // changes  size of the massive of the structs

void Start(); // lanches main functions

#endif /* _HEAD_H_ */