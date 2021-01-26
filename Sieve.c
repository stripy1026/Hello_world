#include <stdio.h>

int Sieve( int *parr, int len )
{
	int i, j;
	
	for ( i = 0; i < len; i++ )
	{
		if ( parr[i] != 0 )
		{
			for ( j = i+1; j < len; j++ )
			{
				if ( parr[j] != 0 && parr[j]%parr[i] == 0 )
				{
					parr[j] = 0;
				}
			}
		printf( "%d ", parr[i] );
		}
	}
	printf( "\n" );
	return ( 0 );
}
int main( void )
{
	int arr[1000];
	int i, N;

	printf( "Insert number you want to sieve. \n" );
	scanf( "%d", &N );

	for ( i = 0; i < N-1; i++ )
	{
		arr[i] = i+2;
	}
	Sieve( arr, i );

	return ( 0 );
}
