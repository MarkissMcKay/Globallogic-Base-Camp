/*
  file:	    Functions.cpp
  
  brief:	Realizes functions  for Exerñise 15 from Task 2
 
  autor:	Shalai Markiian
 */

#include "Head.h"
using namespace std;

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


char ReadDigit( signed short & digit )

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
  
   digit = ( signed short )strtoul( buffer, NULL, 0 );
   
  if( *buffer == 'q' && *(buffer+1) == '\0' )
	  return '0';
  else if( IsDigit(buffer) )
	  return '1';
  else
	  return '2';

}


bool ReadStruct( struct Triangle *triangle, unsigned long i )
{
	if(!ReadCoordinate( ( triangle + i ) -> x1, i, 'X' ))
		return false;
	if(!ReadCoordinate( ( triangle + i ) -> y1, i, 'Y' ))
		return false;

	if(!ReadCoordinate( ( triangle + i ) -> x2, i, 'X' ))
		return false;
	if(!ReadCoordinate( ( triangle + i ) -> y2, i, 'Y' ))
		return false;

	if(!ReadCoordinate( ( triangle + i ) -> x3, i, 'X' ))
		return false;
	if(!ReadCoordinate( ( triangle + i ) -> y3, i, 'Y' ))
		return false;

	return true;
}

bool ReadCoordinate(signed short & digit, unsigned long & i, char coordinate)
{
	char control;
			
	while(1)
		{
			cout << "\n\nEnter the "<< coordinate <<" - coordinate of the" <<i+1<< " -  triangle :  (q - quit)\n\n";
			
			control = ReadDigit(digit);
			
			switch(control)
			{
				case '0':
					return false;
				case '1':
					cout << "One of the symbols you've entered is not digit!\n\n";
					continue;
				case '!':
					cout << "\n\nYou've entered to mach symbols!\n\n";
					continue;
				default:
					cout << "\n\nThe" << coordinate << " - coordinate of the "<<i+1<<" - triangle: "<<digit<<"\n\n";
					break;

			}
			break;
		}
	return true;
}


struct Triangle * Resize( struct Triangle * a, int newsize, int oldsize )
{
    struct Triangle * b = ( struct Triangle * )malloc( sizeof(struct Triangle) * newsize );
		
	memcpy( b, a, sizeof(struct Triangle) * min( oldsize, newsize ) );
 
    free(a);
    
    return b;
}

void PrintStruct( struct Triangle *triangle, unsigned long m )
{
	cout<<"Perimeter: \n\n";

	for( int i  = 0; i < m; i++ )
		cout << (triangle + i) -> perimetr << "\n\n";
}

void Start()
{
	unsigned long newTriangle=1;
	
	char question;
	
	bool q;
	

	Triangle* triangle = (Triangle* )malloc(sizeof(Triangle) * newTriangle);


	if(!ReadStruct( triangle, newTriangle-1 ))
	{
		free(triangle);
		return;
	}
	
	Perimetr( triangle, newTriangle );
	
	Sort( triangle, newTriangle );

	PrintStruct( triangle, newTriangle );

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
			++newTriangle;

			triangle = Resize(triangle, newTriangle, newTriangle-1);

				if(!ReadStruct(triangle, newTriangle-1))
				{
					free(triangle);
					return;
				}

			Sort(triangle, newTriangle);


			PrintStruct(triangle,newTriangle);
		}
		else
			break;
	}

	free(triangle);
	
	return;
}


void Sort( struct Triangle *triangle, unsigned long m )
{

	struct Triangle * tmp = ( struct Triangle * )malloc( sizeof(struct Triangle) * m );

	memcpy( tmp, triangle, sizeof(struct Triangle) * m );

	struct Triangle * temp = ( struct Triangle * )malloc( sizeof(struct Triangle) );
	
	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < m - 1; j++ )
			if( ( tmp + j ) -> perimetr < (tmp + j + 1) -> perimetr )
			{
				memcpy(temp, tmp + j, sizeof(struct Triangle) );
				memcpy( ( tmp + j ), ( tmp + j + 1 ), sizeof(struct Triangle) );
				memcpy( ( tmp + j + 1 ), temp, sizeof(struct Triangle) );
			}
	
	free(temp);

	memcpy( triangle, tmp, sizeof(struct Triangle) * m );

	free(tmp);
}

bool Perimetr( struct Triangle *triangle, unsigned long m )
{

	float side1, side2, side3;

	struct Triangle * tmp = ( struct Triangle * )malloc( sizeof(struct Triangle) * m );

	memcpy( tmp, (triangle), sizeof(struct Triangle) * m );

	for(int i=0;i<m; i++)
	{
		side1 = pow( ( (float)pow( float( (tmp+i) -> x2 - (tmp+i) -> x1 ), 2 ) + (float)pow( float( (tmp+i) -> y2 - (tmp+i) -> y1 ), 2) ), (float)1/2 );

		side2 = pow( ( (float)pow( float( (tmp+i) -> x3 - (tmp+i) -> x1 ), 2 ) + (float)pow( float( (tmp+i) -> y3 - (tmp+i) -> y1 ), 2) ), (float)1/2 );

		side3 = pow( ( (float)pow( float( (tmp+i) -> x3 - (tmp+i) -> x2 ), 2 ) + (float)pow( float( (tmp+i) -> y3 - (tmp+i) -> y2 ), 2) ), (float)1/2 );

		if( side1 == 0 || side2 == 0 || side3 ==0 )
			return false;

		(tmp + i) -> perimetr = side1 + side2 + side3;
	}

	memcpy( (triangle), tmp, sizeof(struct Triangle) * m );

	free(tmp);

	return true;

}