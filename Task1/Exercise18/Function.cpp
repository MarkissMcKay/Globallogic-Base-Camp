/*
  file:	    Functions.h
  
  brief:	Realizes functions  for Exerñise 18 from Task 1
 
  autor:	Shalai Markiian
 */

#include "Head.h"

using namespace std;

bool Function( unsigned long digit ) 
{
  return (bool)( ( digit >> 1 ) & digit ); ;
}

void ShowBinary ( unsigned long digit )
{

	char bin[33];
	
	cout<<"\n\nBinary: ";
	
	puts( itoa( digit, bin, 2 ) );
}

bool IsDigit( char*input )  
{
	bool isDigit=false;
		
	for( int i = 0; i < strlen(input); i++ )
			if( ( input[i] < '0' || input[i] > '9' ) )
			{
				isDigit = true;
			}

		return isDigit;
}

bool ReadULI( unsigned long & digit )
{
	char* input = new char[20];
	
	while(1)
	{
		cout << "Enter the Digit: (q-quit)\n";
		
		gets(input);

		digit = strtoul( input, NULL, 0 );
		
		if( input[0] == 'q' )
		{
			return false;
		}
		else if( IsDigit(input) || digit < 0 || input[0] == '0' )
		{
			cout << "Chack the data you've entered!\n\n" << "Enter the data again:\n";
			
			continue;
		}
		else 
			return true;
	}

	
}
