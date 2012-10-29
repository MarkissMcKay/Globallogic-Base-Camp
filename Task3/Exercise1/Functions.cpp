/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 1 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Functions.h"
using namespace std;

char* Func( char* str, uc & length )
{
	uc templength = length;

	char* pStr;

	char* longestWordPtr;

	pStr = str;

	while( *pStr != '\0' )
	{
		if( *pStr == ' ' )
			length = 0;

		if( *pStr != ' ' )
		{
			while(1)
			{
				if( *pStr == ' ' || *pStr == '\0' )
				{
					if(length > templength)
					{
						longestWordPtr =  --pStr;
						
						templength = length;
					}
					break;
				}
				
				++pStr;
				
				++length;
			}

		}
		
		if( *pStr != '\0' )
			++pStr;
	}
	
	length = templength;
	
	return longestWordPtr;
}


void Sstring(char * str, uc length)
{
	if(!str)
		return;
	
	str = str - ( length - 1 );
	
	char* s = ( char* )malloc( sizeof(char) * length + 1 );

	*( s + length ) = '\0';

	memcpy( s, str, sizeof(char) * length );

	cout<<s<<"\n\n";
	
	free(s);

}