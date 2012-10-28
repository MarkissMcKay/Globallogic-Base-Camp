/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 5 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Functions.h"
#include "Interface.h"
using namespace std;

char* Func( char* str, char* combination, uc & length, uc & startPoint)
{
	uc check=0;

	char* pStr;
	
	pStr = str + ( startPoint - 1 );

	while( *pStr != '\0' )
	{
		if( *pStr != ' ' )
			++length;
		else
			length=0;

		if( *pStr == *combination )
		{
			for( uc i = 1; i < strlen(combination); i++ )
			{
				if( *( pStr + i ) == *( combination + i ) &&  *( pStr + i ) != '\0' )
				{
					++check;
				}
			}

			if( check == strlen(combination) - 1 )
			{
				while(1)
				{
					if( *pStr == ' ' || *pStr == '\0' )
					{
						--length;
						return --pStr;
					}
					++pStr;
					++length;
					++startPoint;
				}
			}

			str = str + ( strlen(combination) - 1 );

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
	
	str = str - ( length - 1 );
	
	char* s = ( char* )malloc( sizeof(char) * length + 1 );

	*( s + length ) = '\0';

	memcpy( s, str, sizeof(char) * length );

	cout <<"\n\n!!!  "<< s << "  !!!\n\n";
	
	free(s);

}
