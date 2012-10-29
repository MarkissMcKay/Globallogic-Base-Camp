/*
  file:	    Head.h
  
  brief:    Defines function prototypes for Exerñise 15 from Task 2
 
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


struct Triangle
{
	signed short x1;
	
	signed short y1;

	signed short x2;
	
	signed short y2;

	signed short x3;
	
	signed short y3;

	double perimetr;
};




void Sort( struct Triangle *p, unsigned long m ); // sorts the structs according some ruel

bool IsDigit( char* input ); // function: returns false in case string it takes is digit, and true otherwise   

char ReadDigit( signed short & digit ); // function that reads (and convert to digit) symbols from keyboard

bool ReadStruct( struct Triangle *triangle, unsigned long i ); // fill the struct's fields with some values

bool ReadCoordinate(signed short & digit, unsigned long & i, char coordinate); // realizes user interface for initialization struct's fields with some values

void PrintStruct( struct Triangle *triangle, unsigned long m ); // prints the fild's values of the structs

struct Triangle * Resize( struct Triangle * a, int newsize, int oldsize );  // changes  size of the massive of the structs

bool Perimetr( struct Triangle *triangle, unsigned long i ); // calculates perimeter of the  triangle 

void Start(); // lanches main functions

#endif /* _HEAD_H_ */