/*
  file:	    Main.h
  
  brief:    Realizes main - function for Exerñise 18 from Task 1
 
  autor:    Shalai Markiian
 */

#include "Head.h"

using namespace std;

int main ()
{
	int kor;

	unsigned long digit;
			
	if( !ReadULI (digit ) )
		return 0;
			
	ShowBinary(digit);

	printf( "\n\nResult: %d",Function( digit ) );

	//return 0;

	cin>>kor;
}