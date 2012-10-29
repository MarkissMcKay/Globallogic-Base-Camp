/*
  file:	    Interface.cpp
  
  brief:	Realizes Interface - functions  for Exerñise 1 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Interface.h"

using namespace std;

bool Interface( char* str, char* toEnter )
{
		char correction;
		
		while(1)
		{
			cout<<"\n\nEnter the " << toEnter << ": (not more than " << strlen(str) << "  symbols) ('q' - exit)\n\n";
			
			correction = ReadChar(str); 
			
			if( correction == '1' )
			{
				cout<<"\n\nYou didn't enter a thing!\n\n";
				continue;
			}
			
			else if(correction == '0' )
				return false;
			
			else if ( correction == '!' )
			{
				cout<<"\n\nYou entered too mach symbols!\n\n";
				continue;
			}
			else
				return true;
		}
}

void Start()
{

uc lengthOfTheLongestWord = 0;

char* longestWord = ( char* )malloc( sizeof(char) * 31 );

*( longestWord + 30 ) = '\0';

loop:

	char* answer = ( char* )malloc( sizeof(char) * 2 );
	
	*( answer + 1 ) = '\0';
	
	bool check;
	
	while(1)
	{
		cout<<"\n\nDo you want to create a new sentence? ('y' - yes, 'n' - no )\n";
	

		if( !Interface( answer, "symbol" ) )
			return;

		if( !strcmp( answer, "y" ) )
		{
			check = true;
			break;
		}
		else if( !strcmp( answer,"n" ) )
		{
			check = false;
			break;
		}
		else
		{
			cout<<"\n\nEnter corect data!\n\n";
			continue;
		}
	}

	if(check)
	{
		uc len=0;

		char* str = ( char* )malloc( sizeof(char) * 31 );

		*( str + 30 ) = '\0';
		
		if( !Interface( str, "sentence" ) )
			return;

		if( PresenceOfTheSymbol( str ) )
		{
		
			cout<<"\n\nThe longest word in this sentence:\n\n";
				
				char* longestWordPtr = Func( str, len );

				Sstring( longestWordPtr, len );

				if(lengthOfTheLongestWord < len)
				{
					longestWordPtr = longestWordPtr - ( len - 1 );

					memcpy( longestWord, longestWordPtr, sizeof(char) * len);
					
					*( longestWord + len ) = '\0';

					lengthOfTheLongestWord = len;
				}

				cout<<"\n\nThe longest word among all sentences: "<<longestWord<<"\n\n";


		}
		
		else
			cout<<"\n\nThere is no any word in this sentence!\n\n";

		free(str);
		free(answer);
		
		goto loop;
	}
	else
	{
		free(longestWord);
		return;
	}

}


char ReadChar(  char* str )

{
	char ch;
	
	char* buffer = ( char* )malloc( sizeof(char) * ( strlen(str) + 1 ) );
	
	char* pBuf = buffer;
	
	uc control = 0, inc = 0;
	
	while(1)
	{
		ch = _getch();
		if( ch != 8 && ch!=13 )
		{
			++control;
			*pBuf = ch;

			if( control > strlen(str) )
			{
				free(buffer);
				return '!';
			}
		}
    
		else if ( ch == 13 )
		{
				break;  
		}
	
		else if ( ch == 8 && control != 0 )
		{
			--inc;
			--control;
			--pBuf;
		}
	  
		printf("\r%80c\r", ' ');
			
		for( uc i = 0; i < control; i++ )
			cout << *( ( pBuf - inc ) + i );
   
		if( ch != 8 )
		{
			++inc;
			++pBuf;
		}
	}
	
	
	*pBuf = '\0';

	if( *buffer == 'q' && *(buffer+1) == '\0' )
	{
		free(buffer);
		return '0';
	}
	
	else if(*buffer == '\0')
	{
		free(buffer);
		return '1';
	}
	
	memcpy( str, buffer, sizeof(char) * ( strlen(buffer) + 1 ) );

	free(buffer);
	
	return '2';


}


bool PresenceOfTheSymbol( char* str )
{
	bool check = false;

	while( *str != '\0' )
	{
		if( *str != ' ' )
		{
			check = true;
			break;
		}
		++str;
	}

	return check;
}