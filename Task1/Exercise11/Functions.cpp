/*
  file:	    Functions.h
  
  brief:	Realizes functions  for Exerñise 11 from Task 1
 
  autor:	Shalai Markiian
 */

#include "Head.h"
using namespace std;

unsigned short Function( unsigned long digit )
{
	unsigned short Result=0;
	unsigned short Control=0;
	
	Control |= ( digit << 31 ) >> 31;
	Result += ( Control | ( ( digit << 31 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 30 ) >> 31 ) | ( ( digit << 30 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 29 ) >> 31 ) | ( ( digit << 29 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 28 ) >> 31 ) | ( ( digit << 28 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 27 ) >> 31 ) | ( ( digit << 27 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 26 ) >> 31 ) | ( ( digit << 26 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 25 ) >> 31 ) | ( ( digit << 25 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 24 ) >> 31 ) | ( ( digit << 24 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 23 ) >> 31 ) | ( ( digit << 23 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 22 ) >> 31 ) | ( ( digit << 22 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 21 ) >> 31 ) | ( ( digit << 21 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 20 ) >> 31 ) | ( ( digit << 20 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 19 ) >> 31 ) | ( ( digit << 19 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 18 ) >> 31 ) | ( ( digit << 18 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 17 ) >> 31 ) | ( ( digit << 17 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 16 ) >> 31 ) | ( ( digit << 16 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 15 ) >> 31 ) | ( ( digit << 15 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 14 ) >> 31 ) | ( ( digit << 14 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 13 ) >> 31 ) | ( ( digit << 13 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 12 ) >> 31 ) | ( ( digit << 12 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 11 ) >> 31 ) | ( ( digit << 11 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 10 ) >> 31 ) | ( ( digit << 10 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 9 ) >> 31 ) | ( ( digit << 9 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 8 ) >> 31 ) | ( ( digit << 8 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 7 ) >> 31 ) | ( ( digit << 7 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 6 ) >> 31 ) | ( ( digit << 6 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 5 ) >> 31 ) | ( ( digit << 5 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 4 ) >> 31 ) | ( ( digit << 4 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 3 ) >> 31 ) | ( ( digit << 3 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 2 ) >> 31 ) | ( ( digit << 2 ) >> 31 ) ) ^ 1;
	Result += ( ( Control |= ( digit << 1 ) >> 31 ) | ( ( digit << 1 ) >> 31 ) ) ^ 1;
	
	return Result;
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
		cout<<"Enter the Digit: (q-quit)\n";
		gets(input);

		digit = strtoul( input, NULL, 0 );
		
		if(input[0]=='q')
		{
			return false;
		}
		else if(IsDigit(input) || digit<0 || input[0]=='0')
		{
			cout<<"Chack the data you've entered!\n\n"<<"Enter the data again: \n";
			continue;
		}
		else 
			return true;
	}

	
}