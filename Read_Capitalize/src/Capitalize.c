/*
 ============================================================================
 Name        : Siddharth Pathak
 UvicID      : V00876495
 Date        : 2016/10/22
 Assignment  : A4
 File name   : V00876495A4P2.c
 ============================================================================

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void read_and_capitalize(){
	char current, last;
	    last=' ';
	    current=getchar();

	while(current != '\n'){

		if(last==' '&&current!=' '){
			current=toupper(current);
			printf("%c",current);

			}

		else if(last!=' '&&current!=' '){
			printf("%c",current);


		}

		else if(last==' '&&current==' '){

		}


			else{
			printf("%c",current);


		}

		//Get the next character from the user
		last=current;
		current = getchar();
	}
	printf("\n");

} /* read_and_capitalize */


int main(void){

	printf("Enter a line of text: ");
	fflush(stdout);
	read_and_capitalize();
	return EXIT_SUCCESS;
} /*main*/

