#include <stdio.h>

int str_add( char *dest, char *src );
int str_compare( char *dest, char *src );

int main( void )
{
	char Library[100][4][100];
	int order, key;
	char input[100];
	int i;
	char input2[100];

	order = 0;

	printf( "\n\n\n+++++++ Welcome to the Library program. ++++++++ \n" );
	printf( "++++ latest update = Tue, 26 January, 2021. ++++ \n" );
	printf( "\n Type \"manual\" if you want to know the commands. \n\n\n" );

	while ( 1 )
	{
		printf( "== Insert a command. == \n" );
		printf( " command : " );
		scanf( "%s", input );
		if ( str_compare( input, "quit" ) )
		{
			printf( "\n Program exited. \n" );
			return( 0 );
		}
		else if ( str_compare( input, "manual" ) )
		{
			printf( " -------------------------------------------------------------- \n" );
			printf( " quit = Exit the program \n" );
			printf( " add = Register a book, order : Title, Author, Publisher \n" );
			printf( " list = Show the list of all books the library has. \n" );
			printf( " search = Search the book with keyword. \n" );
			printf( " borrow = Borrow the book. \n" );
			printf( " return = Return the book you borrowed. \n" );
			printf( " -------------------------------------------------------------- \n\n" );
		}
		else if ( str_compare( input, "list" ) )
		{
			printf( "\n================= LIST =================\n" );
			for ( i = 0; i < order; i++ )
			{
				printf( "Title = %s, Author = %s, Publisher = %s, Borrowed = %s \n",
							Library[i][0], Library[i][1], 
							Library[i][2], Library[i][3] );
			}
			printf( "========================================\n\n" );
		}
		else if ( str_compare( input, "add" ) )
		{
			printf( "\n=== How to add a book === \n" );
			printf( "= Follow the order : \"Title\" \"Author\" \"Publisher\"  \n" );
			printf( "= Type _ between names instead of space bar.  \n" );
			printf( "= ex) Demian Hermann_Hesse Fischer_Verlag  \n\n\n" );
			printf( " Add : " );
			scanf( "%s %s %s", Library[order][0], Library[order][1],
				       	Library[order][2] );
			Library[order][3][0] = 'n';
			Library[order][3][1] = 'o';
			Library[order][3][2] = '\0';
			printf( " < Title : %s, Author : %s, Publisher : %s > is added in Library.\n", 
					Library[order][0], Library[order][1], Library[order][2] );
			order++;
		}
		else if ( str_compare( input, "search" ) )
		{
			printf( "\n=== Type keyword ===\n" );
			printf( "= Type one keyword : \"Title\" , \"Author\" or \"Publisher\"  \n" );
			printf( "= Type _ between names instead of space bar.  \n" );
			printf( "= ex) Hermann_Hesse  \n\n\n" );
			printf( " Search : " );
			scanf( "%s", input2 );
			
			for ( i = 0; i < order; i++ )
			{
				for ( key = 0; key < 3; key++ )
				{
					if ( str_compare( Library[i][key], input2 ) )
					{
						printf( "\n< " );
						printf( "Title = %s, Author = %s, Publisher = %s ",
							Library[i][0], Library[i][1], Library[i][2] );
						printf( "Borrowed = %s >\n\n", Library[i][3] );
					}
				}
			}
		}
		else if ( str_compare( input, "borrow" ) )
		{
			printf( "\n=== How to borrow a book === \n" );
			printf( "= Type the title of book you want to borrow. \n" );
			printf( "= Type _ between names instead of space bar. \n" );
			printf( "= ex) Demian \n\n\n" );
			printf( " Borrow : " );
			scanf( "%s", input2 );
			
			for ( i = 0; i < order; i++ )
			{
				if ( str_compare( Library[i][0], input2 ) )
				{
					Library[i][3][0] = 'y';
					Library[i][3][1] = 'e';
					Library[i][3][2] = 's';
					Library[i][3][3] = '\0';
					printf( " %s is borrowed! \n\n", Library[i][0] );
				}
			}
		}
		else if ( str_compare( input, "return" ) )
		{
			printf( "\n=== How to return your book === \n" );
			printf( "= Type the title of book you want to return. \n" );
			printf( "= Type _ between names instead of space bar. \n" );
			printf( "= ex) Demian \n\n\n" );
			printf( " Return : " );
			scanf( "%s", input2 );

			for ( i = 0; i < order; i++ )
			{
				if ( str_compare( Library[i][0], input2 ) )
				{
					Library[i][3][0] = 'n';
					Library[i][3][1] = 'o';
					Library[i][3][2] = '\0';
					printf( " %s is returned! \n\n", Library[i][0] );
				}
			}
		}
	}
	return( 0 );
}

int str_add( char *dest, char *src )
{
	while ( *dest )
	{
		dest++;
	}
	while ( *src )
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return( 0 );
}
int str_compare( char *dest, char *src )
{
	while ( *dest )
	{
		if ( *dest != *src )
		{
			return( 0 );
		}
		dest++;
		src++;
	}
	if ( *dest == '\0' && *src == '\0' )
	{
		return( 1 );
	}
	return( 0 );
}

