/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 28 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Functions.h"
#include "Interface.h"
using namespace std;

uc NumberOfTheCombinations( char* str, char* combination )
{
	uc number = 0;

	while( *str != '\0' )
	{
		uc check = 0;
		
		if( *str == *combination )
		{
			for(uc i = 1; i < strlen(str); i++)
			{
				if( *( str + i ) == *( combination + i ) )
					++check;
			}
			
			if(check == ( strlen(combination) - 1 ) )
				++number;

			str = str + ( strlen(combination)  - 1 );
		}
		
		++str;
	}

	return number;

}

unsigned short* Resize( unsigned short * a, uc newsize, uc oldsize )
{
    unsigned short * b = ( unsigned short * )malloc( sizeof(unsigned short) * newsize );
		
	memcpy( b, a, sizeof(unsigned short) * min( oldsize, newsize ) );

    free(a);
    
    return b;

}

void BiggestNumber( unsigned short* massOfNumbers, uc numberOfTheSentences, char* combination )
{
	unsigned short temp = 0;

	uc numSentence = 0;

	for( uc i = 0; i < numberOfTheSentences; i++)
		if( temp < *( massOfNumbers + i ) )
		{
			temp = *( massOfNumbers + i );

			numSentence = i + 1;
		}

	if( numSentence == 0 )
		cout << "\n\nThere is no sentence with such symbol combination!\n\n";
	else
		cout << "The biggest number of the "<< combination << " - symbol combinations is " << temp <<" in " << numSentence << " - sentence!";
}