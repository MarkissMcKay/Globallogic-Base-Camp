/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 8 from Task 2
 
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
#include <math.h>


struct Point
{
	signed short x;
	
	signed short y;
	
	signed short z;
};


void Sort( struct Point *p, unsigned long m ); // sorts the structs according some ruel

bool IsDigit( char* input ); // function: returns false in case string it takes is digit, and true otherwise  

char ReadDigit( signed short & digit ); // function that reads (and convert to digit) symbols from keyboard

bool ReadStruct( struct Point *point, unsigned long i ); // fill the struct's fields with some values

bool ReadCoordinate(signed short & digit, unsigned long & i, char coordinate); // realizes user interface for initialization struct's fields with some values

void PrintStruct( struct Point *point, unsigned long m ); // prints the fild's values of the structs

struct Point * Resize( struct Point * a, int newsize, int oldsize ); // changes  size of the massive of the structs

void Start(); // lanches main functions

void Distance( struct Point *point, unsigned long m ); // calculates and shows the shortest distance between two points

#endif /* _HEAD_H_ */