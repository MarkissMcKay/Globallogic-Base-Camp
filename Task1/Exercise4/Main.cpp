/*
  file:	    Main.h
  
  brief:    Realizes main - function for Exerñise 3 from Task 1
 
  autor:    Shalai Markiian
 */

#include "Head.h"
using namespace std;


int main ()
{
	int kor;

	unsigned short firstBit;
	unsigned short secondBit;
	unsigned long digit;
	
	
	if(!ReadULI(digit))
		return 0;
	
	ShowBinary(digit);
	cout<<"Enter the First Bit: (q-quit)\n";
	if(!ReadShort(firstBit))
		return 0;
	cout<<"Enter the Second Bit: (q-quit)\n";
	if(!ReadShort(secondBit))
		return 0;

	printf("\n\nResult: %d",Function( digit, firstBit, secondBit ));
	
	ShowBinary(Function( digit, firstBit, secondBit ));
	cin>>kor;
}