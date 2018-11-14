#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

int LW_LM(int variable, char * pch);
/*
This is a subset of the FT_commands method 
used to handle LM or LW commands.
Variable = LM or LW
pch = value to be added or assigned to LM/LW
*/

int L_S(int variable, char * pch);
/*
This is a subset of the FT_commands method 
used to handle LS command.
Variable = LS
pch = value to be added or assigned to LS
*/

int FT_commands(char * string, int * LM, int * LW, int * FT, int *first_time);
/*
This handles any format commands that come 
at the beginning of the line. It will handle
any invalid parameters or mispelt format
command errors.
string = string passed in
first_time = detects notion of first time for 
	turning on FT if LM or LW were set
*/

char * margins(char *ptr, int LM);
/*
This method appends a margin of a specified
size to a string passed in with it
ptr = string
LM = LM size
*/

char ** increase_size(char ** ptr1,int size);
/*
This method will increase the size of an array of 
pointers dynamically.
ptr1 = array of pointers to expand
size = desired size (usually twice the original size)
*/

char ** format_lines(char ** lines, int *num_lines);
/*
This formats any array of char pointers that is passed in
and calls on all the other methods in this class.
list = array of char pointers
*num_lines = length of list
*/

char ** create_array(FILE *infile, int *count);
/*
This method creates an array of pointers, given a file or
from stdin.
*infile = input stream (file or stdin)
*count = size of array of pointers after it has been made
*/
