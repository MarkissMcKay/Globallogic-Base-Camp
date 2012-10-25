/*
  file:	    Functions.h
  
  brief:	Realizes functions  for Exerñise 3 from Task 2
 
  autor:	Shalai Markiian
 */

#include "Head.h"

using namespace std;

void Function ( struct Factory *p, unsigned long m )
{

	struct Factory * tmp = ( struct Factory * )malloc( sizeof(struct Factory) * m );

	memcpy( tmp, p, sizeof(struct Factory) * m );

	struct Factory * temp = ( struct Factory * )malloc( sizeof(struct Factory) );
	
	for ( int i = 0; i < m; i++ )
		(  tmp + i ) -> percentage = ( (double) ( ( tmp + i ) -> actualyDone ) / (double) ( ( tmp + i ) -> plan ) ) * 100;

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < m - 1; j++ )
			if((tmp + j) -> percentage < (tmp + j + 1) -> percentage)
			{
				memcpy(temp, tmp + j, sizeof(struct Factory) );
				memcpy( ( tmp + j ), ( tmp + j + 1 ), sizeof(struct Factory) );
				memcpy( ( tmp + j + 1 ), temp, sizeof(struct Factory) );
			}
	
	free(temp);

	memcpy( p, tmp, sizeof(struct Factory) * m );

	free(tmp);
}

char* Monthes ( unsigned short i )
{
	char* nameOfMonthes[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	return *(nameOfMonthes +(i - 1));
}

bool IsDigit ( char* input )
{
	bool isDigit = false;
	
	if( *input == '-' || ( *input >= '0' && *input <= '9' ) )
		isDigit = false;
	else
		isDigit = true;
		
	for( int i = 1; i < strlen(input); i++ )
		if( *(input+i) < '0' || *(input+i) > '9' )
			isDigit = true;
		
	return isDigit;
}

char ReadDigit( unsigned short & digit )

{
  char ch;

  char buffer[4];

  char* pBuf = buffer;


  *pBuf = (char)1;

  unsigned short control = 0, inc = 0;


  while(1)
  {
	ch = _getch();
	
	if( ch != 8 )
	control++;
    
	if ( ch == 13 )
    {
	  control--;
	  break;  
    }
	
	if ( ch == 8 && *pBuf != (char)1 )
	{
		--inc;
		--control;
		--pBuf;
		if( control == 0 )
			*pBuf = (char)1;
	}
	
	if( control >= sizeof(buffer) )
		return '!';

	if( ch != 8 )
    *pBuf = ch;
	  
	printf("\r%80c\r", ' ');
	for( int i = 0; i < control; i++ )
		cout << *( ( pBuf - inc ) + i );
   
	if( ch != 8 )
	{
		inc++;
		++pBuf;
	}

  }

   *pBuf = '\0';
  
   if( *buffer == 'q' && *(buffer+1) == '\0' )
	  return '0';
  else if( IsDigit(buffer) )
	  return '1';

  digit = ( unsigned short )strtoul( buffer, NULL, 0 );

  if( digit < 0 )
	  return '2';
  else
	  return '3';

}



bool ReadStruct( struct Factory *st, unsigned long i )
{
	char control;
		
	while(1)
		{
			cout<<"\n\nEnter the number of the month:  (q - quit)\n\n";
			
			control = ReadDigit((st + i) -> monthNumber);
			
			bool chack = false;
			
			for(int j = i - 1; j >= 0; j--)
				if( (st + j) -> monthNumber == (st + i) -> monthNumber )
					chack = true;

			
			if( control == '0' )
				return false;
			
			else if( control == '1' )
			{
				cout << "\n\nSome of the symbols you've entered is not digit!\n\n";
				
				continue;
			}
			
			else if( control == '2' || (st + i) -> monthNumber == 0 || (st + i) -> monthNumber > 12)
			{
				cout << "\n\nYou can not enter negative, zero or more than 12 month number!\n\n";
				
				continue;
			}
			
			else if( control == '!' )
			{
				cout << "\n\nYou've entered to mach symbols!\n\n";
				
				continue;
			}
			
			else if(chack)
			{
				cout << "\n\nYou've already entered this month number!\n\n";
				
				continue;
			}
			
			else
			{
				cout << "\n\n" << i + 1 << " - month number, you've entered : " << (st + i) -> monthNumber << "\n\n";
				
				break;
			}
		}

		while(1)
		{
			cout << "\n\nEnter the quantity of products the factory had to do during " << (st + i) -> monthNumber << " - month according to the plan:  (q - quit)\n\n";
			
			control = ReadDigit((st + i) -> plan);
			
			switch(control)
			{
				case '0':
					return false;
				case '1':
					cout << "One of the symbols you've entered is not digit!\n\n";
					continue;
				case '2':
					cout << "\n\nYou can not enter negative quantity of products!\n\n";
					continue;
				case '!':
					cout << "\n\nYou've entered to mach symbols!\n\n";
					continue;
				default:
					cout << "\n\nQuantity of products, the factory had to do during " << (st + i) -> monthNumber << " - month according to the plan: " << (st + i) -> plan << "\n\n";
					break;

			}
			break;
		}

		while(1)
		{
			cout<<"\n\nEnter the quantity of products the factory has actually done during " << (st + i) -> monthNumber << " - month:  (q - quit)\n\n";
			
			control = ReadDigit((st + i) -> actualyDone);
			
			switch(control)
			{
				case '0':
					return false;
				case '1':
					cout << "One of the symbols you've entered is not digit!\n\n";
					continue;
				case '2':
					cout << "\n\nYou can not enter negative quantity of products!\n\n";
					continue;
				case '!':
					cout << "\n\nYou've entered to mach symbols!\n\n";
					continue;
				default:
					cout << "\n\nQuantity of products the factory has actually done during " << (st + i) -> monthNumber << " - month:" << (st + i) -> actualyDone<<"\n\n";
					break;

			}
			break;
		}
	return true;
}

void PrintStruct( struct Factory *st, unsigned long m )
{
	system("cls");

	cout << "\n\n    Month       Plan      Actually Done      (Actually Done/Plan)*100%\n\n";
	
	for( int i  = 0; i < m; i++ )
		cout << setw(9) << Monthes((st + i) -> monthNumber) << setw(11) << (st + i) -> plan << setw(14) << (st + i) -> actualyDone << setw(24) << (st + i) -> percentage << "\n\n";
}

struct Factory * Resize( struct Factory * a, int newsize, int oldsize )
{
    struct Factory * b = ( struct Factory * )malloc( sizeof(struct Factory) * newsize );
		
	memcpy( b, a, sizeof(struct Factory) * min( oldsize, newsize ) );
 
    free(a);
    
    return b;
}


void Start()
{
	unsigned long newStruct=1;
	
	char question;
	
	bool q;
	
	Factory* factory = (Factory* )malloc(sizeof(Factory) * newStruct);


	if(!ReadStruct( factory, newStruct-1 ))
	{
		free(factory);
		return;
	}
	
	
	Function( factory, newStruct );


	PrintStruct( factory,newStruct );

	while(1)
	{

		while(1)
		{
			cout<<"\n\nDo you want to make new struct? (y - yes, n - no)\n\n";
			
			cin>>question;
			
			if(question=='y')
			{
				q=true;
				break;
			}
			else if(question=='n')
			{
				q=false;
				break;
			}
			else
			{
				cout<<"\n\nEnter correct data!\n\n";
				continue;
			}
		}

		if(q)
		{
			++newStruct;

			factory = Resize(factory, newStruct, newStruct-1);

				if(!ReadStruct(factory, newStruct-1))
				{
					free(factory);
					return;
				}

			Function(factory, newStruct);


			PrintStruct(factory,newStruct);
		}
		else
			break;
	}

	free(factory);
	
	return;
}