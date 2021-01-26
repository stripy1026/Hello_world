#include <stdio.h>

int Get_GCD( int a, int b )
{
	int i = a;
	
	while ( i > 0 )
	{
		i = a%b;
		a = b;
		b = i;
	}
	return ( a );
}
int main( void )
{
	int N, i, num, gcd, temp;

	printf( "Insert the number of numbers.\n" );
	scanf( "%d", &N );

	printf( "Insert the %d numbers.\n", N );
	scanf( "%d", &gcd );

	for ( i = 0; i < N-1; i++ )
	{
		scanf( "%d", &num );

		if ( num > gcd )
		{
			temp = gcd;
			gcd = num;
			num = temp;
		}
		temp = Get_GCD( gcd, num );
		gcd = temp;
	}
	printf( "GCD is : %d \n", gcd );

	return ( 0 );
}






