/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 3 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Functions.h"
using namespace std;

char* Func( char* str, char* symbol, uc & length, uc & startPoint)
{
	char* pStr;

	pStr=str+(startPoint-1);

	while(*pStr!='\0')
	{
		if(*pStr!=' ')
			++length;
		else
			length=0;

		if(*pStr == *symbol)
		{
			while(1)
			{
				if(*pStr==' ' || *pStr=='\0')
				{
					--length;
					return --pStr;
				}
				++pStr;
				++length;
				++startPoint;
			}

		}
		++pStr;
		++startPoint;
	}

	return NULL;
}

void Sstring(char * str, uc length)
{
	if(!str)
		return;
	
	str=str-(length-1);
	
	char* s = ( char* )malloc( sizeof(char) * length+1 );

	*(s+length)='\0';

	memcpy(s, str, sizeof(char) * length );

	cout<<s<<"\n\n";
	
	free(s);

}

