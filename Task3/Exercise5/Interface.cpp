/*
  file:	    Interface.cpp
  
  brief:	Realizes Interface - functions  for Exerñise 5 from Task 3
 
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

			for( uc i = 0; i < strlen(str); i++ )
				if(*(str+i) == ' ')
				{
					correction = ' ';
					break;
				}
			
			if( correction == ' ' && *toEnter == 'c')
			{
				cout<<"\n\nYou can not use 'space' symbol in the symbol combination!\n\n";
				continue;
			}
			else if( correction == '1' )
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
	loop:
	
	char* answer = new char[1];
	
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

		uc startPoint=1;

		char* str = ( char* )malloc( sizeof(char) * 31 );

		*( str + 30 ) = '\0';

		char* combination = ( char* )malloc( sizeof(char) * 4 );

		*( combination + 3 ) = '\0';
		
		if( !Interface( str, "sentence" ) )
			return;
		
		if( !Interface( combination, "combination of the symbols" ) )
			return;

		if( PresenceOfTheCombination( str, combination ) )
		{
		
			cout<<"\n\nThe word(s):\n\n";

			while( startPoint < strlen(str) )
			{
				char* pointer = Func( str, combination, len, startPoint );

				Sstring( pointer, len );
			}

		}
		
		else
			cout<<"\n\nThere is no word with such symbol combination!\n\n";

		free(str);
		free(combination);
		
		goto loop;
	}
	else
		return;

}


char ReadChar(  char* str )

{
	char ch;
	
	char* buffer = ( char* )malloc( sizeof(char) * (strlen(str)+1) );
	
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
	
	memcpy( str, buffer, sizeof(char) * (strlen(buffer)+1));

	free(buffer);
	
	return '2';


}


bool PresenceOfTheCombination( char* str, char* combination )
{
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
				return true;

			str = str + ( strlen(combination)  - 1 );
		}
		
		++str;
	}

	return false;

}