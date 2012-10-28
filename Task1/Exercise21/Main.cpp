/*
  file:	    Main.cpp
  
  brief:    Realizes main - function for Exerñise 21 from Task 1
 
  autor:    Shalai Markiian
 */

#include <iostream>
#include "Head.h"

using namespace std;

int main ()
{
	signed long digit;
	
	if( !ReadSLI(digit) )
		return 0;
	
	ShowBinary(digit);
	
	cout << "\n\nResult: " << Function(digit);

	return 0;
}