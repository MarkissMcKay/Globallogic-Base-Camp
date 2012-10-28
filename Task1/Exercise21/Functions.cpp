/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 21 from Task 1
 
  autor:	Shalai Markiian
 */

#include "Head.h"

using namespace std;

signed short Function( signed long digit )
{
	return ( ( digit >> ( ( sizeof( signed long int ) << 3 ) - 1 ) ) & digit );
}

void ShowBinary( signed long digit )
{
	char bin[33];
	
	cout << "\n\nBinary: ";
	
	puts(itoa( digit, bin, 2 ));
}


bool IsDigit( char* input )
{
	bool isDigit=false;
	
	if( input[0] == '-' || ( input[0] > '0' && input[0] < '9' ) )
		isDigit=false;
		
	for( int i = 1; i < strlen(input); i++ )
		if( input[i] < '0' || input[i] > '9' )
		{
			isDigit=true;
		}

		return isDigit;
}


bool ReadSLI( signed long & digit )
{
	char* input = new char[20];
	
	while(1)
	{
		cout << "Enter the Digit: (q-quit)";
		
		gets(input);

		digit = strtoul( input, NULL, 0 );
		
		if( input[0] == 'q' )
		{
			return false;
		}
		else if( IsDigit(input) || input[0] == '0' )
		{
			cout << "Chack the data you've entered!\n\n" << "Enter the data again: ";
			
			continue;
		}
		else 
			return true;
	}

	
}