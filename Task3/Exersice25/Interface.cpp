/*
  file:	    Interface.cpp
  
  brief:	Realizes Interface - functions  for Exerñise 25 from Task 3
 
  autor:	Shalai Markiian
 */

#include "Interface.h"

using namespace std;

bool Interface( char* str, char* toEnter )
{
		char correction;
		
		while(1)
		{
			cout << "\n\nEnter the " << toEnter << ": (not more than " << strlen(str) << "  symbols) ('q' - exit)\n\n";
			
			correction = ReadChar(str); 
			
			if( correction == '1' )
			{
				cout << "\n\nYou didn't enter a thing!\n\n";
				continue;
			}
			
			else if(correction == '0' )
				return false;
			
			else if ( correction == '!' )
			{
				cout << "\n\nYou entered too mach symbols!\n\n";
				continue;
			}
			else
				return true;
		}
}

void Start()
{
	loop:
	
	char* answer = ( char* )malloc( sizeof(char) * 2 );
	
	*( answer + 1 ) = '\0';
	
	bool check;

	 bool  firstLanch = false;
	
	while(1)
	{
		cout << "\n\nDo you want to create a new sentence? ('y' - yes, 'n' - no )\n";
	

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
			cout << "\n\nEnter corect data!\n\n";
			continue;
		}
	}

	if(check)
	{
		uc len=0;

		uc startPoint=1;

		char* str = ( char* )malloc( sizeof(char) * 31 );

		*( str + 30 ) = '\0';
				
		char* reverseStr = ( char* )malloc( sizeof(char) * 31 );

		char* sTemp = ( char* )malloc( sizeof(char) * 31 );
		
		if( !Interface( str, "sentence" ) )
			return;


		if( PresenceOfTheWord( str ) )
		{
		
			cout << "\n\nSentence in reverse order:\n\n";

			while( startPoint < strlen(str) )
			{
				char* pointer = Func( str, len, startPoint );

				Sstring( pointer, len, reverseStr, sTemp, firstLanch );
			}
			
			cout << reverseStr<<"\n\n";

		}
		
		else
			cout << "\n\nThere is no any word in this sentence!\n\n";

		free(str);
		
		free(reverseStr);
		
		free(sTemp);
		
		free(answer);
		
		goto loop;
	}
	else
		return;

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
	  
		printf( "\r%80c\r", ' ' );
			
		for( uc i = 0; i < control; i++ )
			cout << *( ( pBuf - inc ) + i );
   
		if( ch != 8 )
		{
			++inc;
			
			++pBuf;
		}
	}
	
	
	*pBuf = '\0';

	if( *buffer == 'q' && *( buffer + 1 ) == '\0' )
	{
		free(buffer);
		return '0';
	}
	
	else if( *buffer == '\0' )
	{
		free(buffer);
		
		return '1';
	}
	
	memcpy( str, buffer, sizeof(char) * ( strlen(buffer) + 1 ) );

	free(buffer);
	
	return '2';
}


bool PresenceOfTheWord( char* str )
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