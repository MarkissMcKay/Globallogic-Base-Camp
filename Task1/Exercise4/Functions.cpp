/*
  file:	    Functions.h
  
  brief:	Realizes functions  for Exerñise 3 from Task 1
 
  autor:	Shalai Markiian
 */

#include "Head.h"

using namespace std;

unsigned long Function( unsigned long digit, short firstBit, short secondBit )
{
  return ( ( digit ^ ( HelpFunction(digit, firstBit, secondBit) << firstBit ) ) ^ ( HelpFunction(digit, firstBit, secondBit) << secondBit ) );
}

unsigned long HelpFunction( unsigned long digit, short firstBit, short secondBit )
{
  return ( ( ( digit >> firstBit ) ^ ( digit >> secondBit ) ) << 31 ) >> 31;
}

void ShowBinary( unsigned long digit )
{
	char bin[33];
	cout<<"\n\nBinary: ";
	puts(itoa( digit, bin, 2 ));
}


bool IsDigit( char*input )
{
	bool isDigit=false;
		
	for(int i=0;i<strlen(input);i++)
		if((input[i]<'0' || input[i]>'9'))
		{
			isDigit=true;
		}

		return isDigit;
}


bool ReadULI( unsigned long & digit )
{
	char*input=new char[20];
	
	while(1)
	{
		cout<<"Enter the Digit: (q-quit)";
		gets ( input );

		digit = strtoul( input, NULL, 0 );
		
		if(input[0]=='q')
		{
			return false;
		}
		else if(IsDigit(input) || digit<0 || input[0]=='0')
		{
			cout<<"Chack the data you've entered!\n\n"<<"Enter the data again: ";
			continue;
		}
		else 
			return true;
	}

	
}

bool ReadShort( unsigned short & Digit )
{
	char*input=new char[10];
	 while(1)
	{
		
		gets(input);

		Digit = (unsigned short)strtoul( input, NULL, 0 );
		
		if(input[0]=='q')
			return false;
		else if( IsDigit(input) || Digit<0 || input[0]=='0' || Digit>31 )
		{
			cout<<"Chack the data you've entered!\n\n"<<"Enter the data again: ";
			continue;
		}
		else 
			return true;
	}
}