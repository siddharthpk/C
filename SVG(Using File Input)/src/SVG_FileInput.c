/*
 ============================================================================
Name        : Siddharth Pathak
UVicID      : V00876495
Date        : 2016/11/22
Assignment  : A6
File name   : V00876495A6P2.c
Description : This program reads shapes from file and produces it's SVG representation.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define INPUT_FILENAME    ("shapes_input.txt")
#define OUTPUT_FILENAME   ("shapes_output.html")

/* Size of the canvas - Do not change */
#define CANVAS_SIZE 800
#define CANVAS_SIZE_X CANVAS_SIZE
#define CANVAS_SIZE_Y CANVAS_SIZE

#define MAX_LINE_LENGTH 1000

void process_shapes(FILE* ifp, FILE* ofp) {
	char line[MAX_LINE_LENGTH];

	/* Read each line from the input file with fgets */
	if (!ofp){
			printf("writePrologue error: output file == NULL\n");
			exit(1);
		}
		fputs("<!DOCTYPE html>\n",ofp);
		fputs("<html>\n",ofp);
		fputs("<head>\n",ofp);
		fputs("<title>CSC 111 Fall 2016 -  Assignment 6 Part 2</title>\n",ofp);
		fputs("</head>\n",ofp);
		fputs("<body>\n",ofp);
		fputs("CSC 111 Art: <br />\n",ofp);
		fprintf(ofp,"<svg width=\"%dpx\" height=\"%dpx\">\n\n",CANVAS_SIZE_X,CANVAS_SIZE_Y);
	while(fgets(line, MAX_LINE_LENGTH, ifp) != NULL){
		/* Your code here */
		char shape_name[100];
		float a,b,c,d,e,f,g,h;
		sscanf(line,"%s %f %f %f %f %f %f %f %f",shape_name,&a,&b,&c,&d,&e,&f,&g,&h);
		if(strcmp(shape_name,"SQUARE")==0){
			fprintf(ofp,"<rect x=\"%.0f\" y=\"%.0f\" width=\"%.0f\"  height=\"%.0f\" style=\"fill:rgb(%.0f,%.0f,%.0f); fill-opacity:%.1f\"/>\n",a,b,c,c,d,e,f,g);
		}

		if(strcmp(shape_name,"RECTANGLE")==0){
			fprintf(ofp,"<rect x=\"%.0f\" y=\"%.0f\" width=\"%.0f\" height=\"%.0f\" style=\"fill:rgb(%.0f,%.0f,%.0f); fill-opacity:%.1f\"/>\n",a,b,c,d,e,f,g,h);
		}

		if(strcmp(shape_name,"ELLIPSE")==0){
			 fprintf(ofp,"<ellipse cx=\"%.0f\" cy=\"%.0f\" rx=\"%.0f\" ry=\"%.0f\" style=\"fill:rgb(%.0f,%.0f,%.0f); fill-opacity:%.1f\"/>\n",a,b,c,d,e,f,g,h);

		}

		if((strcmp(shape_name,"CIRCLE")==0)){
			fprintf(ofp,"<circle cx=\"%.0f\" cy=\"%.0f\" r=\"%.0f\" style=\"fill:rgb(%.0f,%.0f,%.0f); fill-opacity:\%.1f\"/>\n",a,b,c,d,e,f,g);
		}

		printf("%s", line);
	}

				fputs("\n</svg>\n",ofp);
				fputs("</body>\n",ofp);
				fputs("</html>\n",ofp);
} /* process_shapes */

int main(void) {
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

	process_shapes(ifp, ofp);

	fclose(ofp);
	fclose(ifp);
	return EXIT_SUCCESS;
} /*main*/
