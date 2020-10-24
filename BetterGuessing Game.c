#include <stdio.h>

void gameMode ( int lives , int min , int max ) ;

int main ( ) {
	
	int sleep ( ) ;
	int system ( ) ;
	int count = 0 ;
	char line = '=' ;
	
//welcome message
	system ( "clear" ) ;
	printf ( "\t" ) ;
	do {
		printf ( "%c" , line ) ;
		count++ ;
	}
	while ( count < 60 ) ;
	
	printf ( "\n\t\t\tWelcome to the Guessing Game!\n" ) ;
	count = 0 ;
	
	printf ( "\t" ) ;
	do {
		printf ( "%c" , line ) ;
		count++ ;
	}
	while ( count < 60 ) ;
	
	printf ( "\n" ) ;
	sleep ( 2 ) ;
		pick :
//initiate game
	printf ( "\n\t\t\tDo you want to play? Y/N : " ) ;
	char a ;
	scanf ( "%s" , &a ) ;
	
	if ( a == 'Y' || a == 'y' ) {
		printf ( "\n\t\t\t\t  Awesome!" ) ;
		printf ( "\n" ) ;
		sleep ( 1 ) ;
		system ( "clear" ) ;
		goto start ;
	}
	if ( a == 'N' || a == 'n' ) {
		printf ( "\n\t\t\t\tIf You Say So\n" ) ;
		printf ( "\n" ) ;
		goto exit ;
	}
	else {
		printf ( "\n\t\t\t    ERROR INVALID INPUT" ) ;
		printf ( "\n" ) ;
		sleep ( 1 ) ;
		system ( "clear" ) ;
		goto pick ;
	}
		start :
//difficulty select
	system ( "clear" ) ;
	char d ;
	printf ( "\n\n\n\n\t\t\t    Select Difficulty\n" ) ;
	printf ( "\t\t\t     Easy 'E'\n" ) ;
	printf ( "\t\t\t     Medium 'M'\n" ) ;
	printf ( "\t\t\t     Hard 'H'\n" ) ;
	printf ( "\t\t\t     Impossible 'I'\n" ) ;
	printf ( "\n\t\t\t\t   " ) ;
	scanf ( "%s" , &d ) ;
	
	sleep ( 1 ) ;
//game modes
	switch ( d ) {
		case 'E' : case 'e' :
			printf ( "Wow really?\n\n" ) ;
			gameMode ( 3 , 1 , 5 ) ;
			break ;
		case 'M' : case 'm' :
			printf ( "Meh it's not that impressive.\n\n" ) ;
			gameMode ( 3 , 1 , 10 ) ;
			break ;
		case 'H' : case 'h' :
			printf ( "Now this is an actual challenge.\n\n" ) ;
			gameMode ( 4 , 1 , 100 ) ;
			break ;
		case 'I' : case 'i' :
			printf ( "Oof someone is going to flip.\n\n" ) ;
			gameMode ( 5 , 1 , 1000 ) ;
			break ;
		default :
			printf ( "\n\t\t\t  ERROR INVALID INPUT" ) ;
			printf ( "\n" ) ;
			sleep ( 1 ) ;
			goto start ;
	}

		again :
//asking to play again if they win or lose
	printf ( "\n\t\t  Do you want to play again? Y/N : " ) ;
	scanf ( "%s" , &a ) ;
	
	if ( a == 'Y' || a == 'y' ) {
		printf ( "\n\t\t\t\tAwesome!" ) ;
		printf ( "\n" ) ;
		sleep ( 1 ) ;
		system ( "clear" ) ;
		goto start ;
	}
	if ( a == 'N' || a == 'n' ) {
		printf ( "\n\t\t\t     If You Say So\n" ) ;
		printf ( "\n" ) ;
		goto exit ;
	}
	else {
		printf ( "\n\t\t\t     ERROR INVALID INPUT" ) ;
		printf ( "\n" ) ;
		sleep ( 1 ) ;
		system ( "clear" ) ;
		goto again ;
	}
		
		exit : 
 //quitting game graphics
	sleep ( 2 ) ;
	printf ( "\nSelf Destruct In\n" ) ;
	
	int countDown [ 5 ] ;
	int i ;
	int j ;
//over complicated to show off skills
	sleep ( 1 ) ;
	for ( j = 1 , i = 0 ; j <= 5 ; i++ , j++ ) {
		countDown [ i ] = j ;
		}
		for ( i = 4 ; i >= 0 ; i-- ) {
			printf ( "%d\n" , countDown [ i ] ) ;
			sleep ( 1 ) ;
		}
	printf ( "*BOOM!*\n" ) ;
	sleep ( 1 ) ;
	
	return 0 ;
}

//definition of gameMode
void gameMode ( int lives , int min , int max ) {
		
	int sleep ( ) ;
	int system ( ) ;
	int num ;
	int g ;
	int repeat = 1 ;
	
	top :
		printf( "Pick A Number Between %d and %d To Be Guessed. " , min , max ) ;
		scanf ( "%d" , &g ) ;
		if ( g < min || g > max ) {
			goto top ;
		}
			else
		sleep ( 1 ) ;
		system ( "clear" ) ;
		printf ( "\t\t\t    You get %d Lives\n\n" , lives ) ;
			repeate :
	if ( repeat != 0 ) {
		if ( lives != 0 ) {
			printf ( "Pick A Number Between %d and %d : " , min , max ) ;
			sleep ( 1 ) ;
			scanf ( "%d" , &num ) ;
				if ( num < min || num > max ) {
					printf ( "\n\t\t\t  INVALID INPUT IDIOT\n\n" ) ;
					goto repeate ;
				}
				else if ( num != g ) {
					sleep ( 1 ) ;
					printf ( "\n\t\t\t\t Wrong\n" ) ;
					lives-- ;
					printf ( "\t\t      You Have %d Lives Remaining\n\n" , lives ) ;
					if ( num > g ) {
						sleep ( 1 ) ;
						printf ( "%d > ?\n" , num ) ;
						goto repeate ;
					}
					else if ( num < g ) {
						sleep ( 1 ) ;
						printf ( "%d < ?\n" , num ) ;
						goto repeate ;
					}
					else
					goto repeate ;
				}
				else
				sleep ( 1 ) ;
				printf ( "\n\t\t       CONGRATULATIONS! YOU WIN!" ) ;
				sleep ( 1 ) ;
				repeat-- ;
				goto repeate ;
			}
			else
			sleep ( 1 ) ;
			printf ( "\n\t\t\t\tYou Lose!" ) ;
			printf ( "\n" ) ;
			sleep ( 1 ) ;
			printf ( "\n\t\t        The number was %d dummy!" , g ) ;	
			printf ( "\n\n" ) ;
			sleep ( 1 ) ;
			repeat -- ;
			goto repeate ;
		}
	}
