/*
 * UVic SENG 265, Summer 2018, A#4
 *
 * This will contain a solution to uvroff2.c In order to complete the
 * task of formatting a file, it must open the file and pass the result
 * to a routine in formatter.c.
 */

#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"

int main(int argc, char *argv[]) {
#ifdef DEBUG
    int num_lines;
    int i;
    char **result;
    char **list;
    FILE *infile;
    
	if (argc < 2) {
	/*get input from stdin*/
	list = create_array(stdin,&num_lines);
	}else{
		/*Open file*/
		infile = fopen(argv[1], "r");
		if (infile == NULL) {
			fprintf(stderr, "%s cannot open file named %s\n", argv[0], argv[1]);
			exit(1);
		}
		list = create_array(infile, &num_lines);		
	}

    result = format_lines(list, &num_lines);
    for (i = 0; i < num_lines; i++, result++) {
        printf("%s\n", *result);
    }
#endif
	exit(0);
}