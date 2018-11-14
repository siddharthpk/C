#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
#define MAX_LINE_LEN 133 /* max 132 char per line plus one extra for the newline char*/
#define MAX_LINES 300 /* max 300 lines per input file  */
#define MAX_CHARS 39900 /* max number of characters in the file */
  
/*Initializes array used to store lines read in from text file as well as output array */
char input[MAX_LINE_LEN];
char buffer[MAX_CHARS];
char word_wrap[MAX_LINE_LEN];
 
/* Functions */
void parameters(char [], FILE *);
 
/* Variables */
int width = 0;
int left = 0;
int format=0; 
int linespacing=0;

/*
argc is the count of input arguments
argv is a pointer to the input arguments
*/

int main (int argc, char *argv[])
{
    /* Creates file pointer */
    FILE *fp = fopen(argv[1], "r"); /* r for read */

    if (!fp) /* Error checking */
     {
         printf("Error: Could not open file");
         return 0;
     }
         
    /* Retrieves width,margin,formatting and linespacing parameters from input file */
     parameters(input, fp);
 
     fclose(fp);     /* Closes file stream */
 
     return 0;
 }
 
void parameters(char input[], FILE *fp)
{
    /* Gets input file text line by line */
    while (fgets (input, 133, fp) != NULL)
    {
        /* Creates a pointer to traverse array */
        char *p = input;

        /* Checks for width parameter read in from text file */
        if (input[0] == '.' && input [3] == 'W')
         {
               strtok(input, " ");    /* Eliminates first token*/ 
               width = atoi(strtok(NULL, " "));    /* Stores int value of ASCII token*/
               p = NULL;
         }

        /* Checks for margin parameter read in from text file */
        if (input[0] == '.' && input[3] == 'M')
         {
              strtok(input, " ");                  /* Eliminates first token */
              left  = atoi(strtok(NULL, " "));    /* Stores int value of ASCII token*/
              p = NULL;
         }
	
	/*Checks for linespacing parameter read in from text file*/
	if (input[0]=='.' && input[3] == 'S')
	 {
	      strtok(input," "); 		  /*Eliminates first token*/
	      linespacing = atoi(strtok(NULL, " ")); /*Stores int value of ASCII token*/	
 	      p=NULL;

	 }
	/*Checks for formatting parameter read in from text file*/
	 if (p != NULL)      /* skips printing format tokens at beginning of file */
         {
            if (width == 0)     /* no width command, formatting is off by default */
             {   format=0;
		 left=0;
                 printf("%s", p); /* Prints unformatted line of text */
             }
            else    /* formatting is on */
             {   format=1;
                 printf("%*s" "%s", left, " ",  p); /* Prints formatted line of text*/
             }
         }
     }
 }
