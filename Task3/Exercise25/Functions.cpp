/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 25 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Functions.h"

using namespace std;

static int k = 0;

char* Func( char* str, uc & length, uc & startPoint)
{
	char* pStr;

	pStr = str + ( startPoint - 1 );

	while( *pStr != '\0' )
	{
		if( *pStr == ' ' )
			length=0;

		if( *pStr != ' ' )
		{
			while(1)
			{
				if( *pStr == ' ' || *pStr == '\0' )
					return --pStr;
				
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

void Sstring( char * str, uc length, char* reverseStr, char* sTemp, bool & firstLanch )
{
	if(!str)
		return;

	str = str - ( length - 1 );
	
	char* s = ( char* )malloc( sizeof(char) * length + 1 );

	*( s + length ) = '\0';

	memcpy(s, str, sizeof(char) * length );

	strcpy( reverseStr, s );
	
	if(firstLanch)
	{
		strcat( reverseStr, " " );
		
		strcat( reverseStr, sTemp );
		
		strcpy( sTemp, reverseStr );
	}
	else
		strcpy( sTemp, s );

	firstLanch = true;

	free(s);

}