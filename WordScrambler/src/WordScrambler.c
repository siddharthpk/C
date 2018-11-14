/*
 ============================================================================
Name        : Siddharth Pathak
UVicID      : V00876495
Date        : 2016/11/21
Assignment  : A6
File name   : V00876495A6P1.c
Description : This program reads and scrambles the words in a text file.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME    ("A6P1_2016_TestingSherlock.txt")
#define OUTPUT_FILENAME   ("A6P1_2016_SherlockEncoded.txt")
#define MAXLINE 10000// added so that changing the code is simple

void process_file(FILE* ifp, FILE* ofp) {
	printf("Begin file processing\n");
    /* Your code here */
	char line[MAXLINE],c;
	char word[MAXLINE];
    int l_idx=0,w_idx=0,count=0;
	int j,word_counttotal,k;
	k=0;// used for putting max 50 words in a line
	word_counttotal=0;// used for total no. of words in the file

	while(fgets(line,MAXLINE,ifp)!=NULL){
        l_idx=0;
    	while(line[l_idx]!='\0'){

		char input=line[l_idx];

		if(isspace(input)){
			word_counttotal++;
			k++;

			if(w_idx!=0){
            	word[w_idx]='\0';
            	count=strlen(word);

            	if(count>=4){

            		for(j=1;j<count-1;j++){
    					            c=word[j];
    					    		word[j]=word[count-2];
    					    		word[count-2]=c;
    				}

            	}           if(k<=50){
            				fprintf(ofp,"%s ",word);}
            	else
            	{
            		fprintf(ofp,"\n");
            		k=0;
            	}
            				w_idx=0;

            }
		}

		else{
			word[w_idx]=input;
			w_idx++;
			}

		l_idx++;

	 }

    	if(w_idx!=0){
    	    	word[w_idx]='\0';
    	    	count=strlen(word);
    	    	for(j=1;j<count-1;j++){
    	    	    		c=word[j];
    	    	    		word[j]=word[count-3];
    	    	    	    word[count-3]=c;
    	    	    				}
    	    		fprintf(ofp,"%s\n",word);

    	    }

   }
    printf("%d",word_counttotal-1);
	printf("\nEnd file processing\n");
} /* process_file */

int main(void) {
	printf("Starting text encoding...\n\n");
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);

	FILE* ifp = fopen(INPUT_FILENAME, "r");
	if (ifp == NULL) {
		printf("Cannot open input file %s\n", INPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /* if */

	FILE* ofp = fopen(OUTPUT_FILENAME, "w");
	if (ofp == NULL) {
		printf("Cannot create output file %s\n", OUTPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /* if */

	process_file(ifp, ofp);

	fclose(ofp);
	fclose(ifp);
	printf("\nEncoding finished.\n");
	return EXIT_SUCCESS;
} /*main*/
