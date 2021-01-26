#include <stdio.h>

int main( void ) {

	int N, i, num, j;

	printf( "====Integer factorization program====\n" );
	printf( "Please input the number you want to divide. \n" );

	scanf( "%d", &N );
	num = N;
	
	printf( " %d = ", N );

	if ( num == 1 ) {
		printf( "%d \n", 1 );
		return 0;
	}

	for ( i = 0; i < 1000; i++ ) {

		if ( num == 1 ) {
			break;
		}

		if ( i > 0 ) {
			printf( " * " );
		}
		for ( j = 2; ; j++ ) {

 		        if ( num%j == 0 ) {
			        printf( "%d", j );
			        num /= j;
				break;
			}
		}
	}
	printf( "\n" );

	return 0;
}



		
