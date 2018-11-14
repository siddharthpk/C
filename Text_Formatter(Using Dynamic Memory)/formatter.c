/*
 * UVic SENG 265, Summer 2018, A#4
 *
 * This will contain the bulk of the work for the fourth assignment. It
 * provide similar functionality to the class written in Python for
 * assignment #3.
 */

#include "formatter.h"

/*
 * Some constants
 */
#define FMT_OFF 0
#define FMT_ON 1
#define TRUE 1
#define FALSE 0

/* METHOD: int LW_LM
 * PARAMETERS: 1st = LM or LW, 2nd = token w/ parameter
 * RETURN: variable value for either LM or LW
 * DESCRIPTION: Handles values for LM or LW.
 */
 
int LW_LM(int variable, char * pch){
	int value;
	if(strcmp(pch,"0")!=0){
		value = atoi(pch); /*convert token into an int*/
		if (value==0) { /*If pch is a non-numeric char, it will be 0*/
			fprintf(stderr,"Invalid parameter in LM or LW. Exiting.\n");
			exit(1);
		}
		
		if (strchr(pch,'+') || strchr(pch,'-')) {
			variable += value; /*Add value to current LM or LW or LS*/
		}else{
			variable = value; /*Assign new value to LM or LW or LS*/
		}
		
	}else{
		variable = 0;
	}
	return variable;
}

/* METHOD: int L_S
 * PARAMETERS: 1st = LS 2nd = token w/ parameter
 * RETURN: variable value for either LM or LW
 * DESCRIPTION: Handles values for LM or LW.
 */
 
int L_S(int variable, char * pch){
	int value;
	if(strcmp(pch,"0")!=0){
		value = atoi(pch); /*convert token into an int*/
		if (value==0) { /*If pch is a non-numeric char, it will be 0*/
			fprintf(stderr,"Invalid parameter in LM or LW. Exiting.\n");
			exit(1);
		}
		if (value==0) { /*If pch is a non-numeric char, it will be 0*/
			fprintf(stderr,"Invalid parameter in LM or LW. Exiting.\n");
			exit(1);
		}
		if (strchr(pch,'+') || strchr(pch,'-')) {
			variable += value; /*Add value to current LS*/
		}else{
			variable = value; /*Assign new value to LS*/
		}
		
	}else{
		variable = 0;
	}
	return variable;
}


/* METHOD: int FT_commands
 * PARAMETERS: A string of text, LM, page width, FT, and LS respectively
 * RETURN: 1 for format command being handled, 0 for no format command
 * DESCRIPTION: Will check for instances of format commands at the beginning of the 
 * line; does some basic error handling for misspelled format commands and invalid
 * parameters. It also will check to ensure that the LM is always less than or
 * equal to the page width by 20 and LS is not bigger than 2.
 */
int FT_commands(char * string, int * LM, int * LW, int * FT, int * LS){
	char * pch;
	if (string[0]=='.') {
		pch = strtok(string," ");
		
		/*Is first token == ".LM" ?*/
		if (strcmp(pch,".LM")==0) {
			
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for LM. Exiting.\n");
				exit(1);
			}
			*LM = LW_LM(*LM,pch);	
		/*Is first token == ".LW" ?*/	
		}else if (strcmp(pch,".LW")==0) {
		
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for LW. Exiting.\n");
				exit(1);
			}			
			*LW = LW_LM(*LW,pch);	
		/*Is first token == ".FT" ?*/				
		}else if(strcmp(pch,".FT")==0){
		
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for FT. Exiting.\n");
				exit(1);
			}			
			if (strcmp(pch,"off")==0) { /*Check if is it off*/
				*FT = FMT_OFF; 
			}else if (strcmp(pch,"on")==0) { /*Check if is it on*/
				*FT = FMT_ON;
			}else{
				fprintf(stderr,"Invalid parameter in FT. Exiting.\n");
				exit(1);
			}
		
		/*There was a dot at beginning of string, but no valid format command*/
		/*Is first token == ".LS" ?*/
		}else if(strcmp(pch,".LS")==0){
		
			
			
			pch = strtok(NULL, " ");
			if(pch==NULL){
				fprintf(stderr,"No parameter specified for LM. Exiting.\n");
				exit(1);
			}
			*LS = L_S(*LS,pch);



		}else{
			
			fprintf(stderr,"Invalid formatting command, check for dot at the beginning of a line. Exiting.\n");
			exit(1);
		}
	/*If no dot at beginning of string, assumed to be text*/	
	}else{
		return 0; 
	}
	
	/*Default behaviour*/
	if(*LM != 0 || *LW !=0) {
		*FT = FMT_ON;
		//*first_time=1;
	}
	
	/*Check if LW or LM have invalid integer values*/
	if(*LM < 0) {
		*LM = 0;
	}
	if(*LW < 20) {
		*LW = 20;
	}
	if (*LM > *LW - 20) {
		*LM = *LW - 20;
	}
	if (*LS > 2){
		*LS = 0;	
	}
	
	return 1; /*Implies that a format command was processed*/
}/*end FT_commands*/


/* METHOD: char* margins
 * PARAMETERS: String, size of LM
 * RETURN: Pointer
 * DESCRIPTION: Adds spaces to the beginning of the string.
 */
char * margins(char *ptr, int LM){
	int i;
	char *temp = malloc (sizeof(char)*(LM+1));
	if(temp==NULL){
		fprintf(stderr,"Error in dynamically allocating memory");
		exit(1);
	}
	for(i=0;i<LM;i++){
		*(temp+i) = ' ';
	}
	*(temp+LM) = '\0';
	*(ptr) = '\0';
	strncat (ptr,temp,LM+1);
	free(temp);
	return ptr;
}


/* METHOD: char* spacing
 * PARAMETERS: String, size of LS
 * RETURN: Pointer
 * DESCRIPTION: Adds a blank line after the string.
 */
char * spacing(char *ptr, int LS){
	int i;
	char *temp = malloc (sizeof(char)*(LS+1));
	if(temp==NULL){
		fprintf(stderr,"Error in dynamically allocating memory");
		exit(1);
	}
	if(LS > 2){
		fprintf(stderr,"Invalid LS input.\n");
		LS=0;	
	}
	for(i=0;i<LS;i++){
		*(temp+i) = '\n';
	}
	*(temp+LS) = '\n';
	*(ptr) = '\n';
	strncat (ptr,temp,LS+1);
	free(temp);
	return ptr;
}


/* METHOD: char ** increase_size
 * PARAMETERS: array of pointers, new size
 * RETURN: the new pointer
 * DESCRIPTION: Doubles the size of the dynamically allocated array.
 */
char ** increase_size(char ** ptr1,int size) {
	char ** temp;
	temp = ptr1;
	temp = (char **) realloc(ptr1, size*sizeof(char *));
	if(temp==NULL){
	
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);
	}
	return temp;

}


/* METHOD: char ** format_lines
 * PARAMETERS: your array of string pointers and the # of elements in the array.
 * RETURN: A new array of string pointers that is formatted
 * DESCRIPTION: This will format your text. Will call on other methods to deal
 * with format command handling, margins,linespacing and page widths.
 */

char ** format_lines(char ** lines, int *num_lines){
	char ** result = NULL;
	int LM=0;
	int LW=20;
	int FT = FMT_OFF;
	int LS = 0;
	
	char * pch;
	int i;
	int cur_pos = 0; /*current position of line*/
	int cur_len = 0;
	int result_max;
	
	int partial_array = 0;
	
	result = (char **) malloc(sizeof(char *));
	result_max = 1;
	if (result == NULL) {
	
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);	
	}	
	
	/*For each line*/

	for(i = 0;i<*num_lines;i++){
		
		/*Is array of string pointers full?*/
		if (cur_len>=result_max) {
			result_max *= 2;
			result = increase_size(result,result_max);
		}
		
		/*Process any format commands, result doesn't increase in size*/
		if( FT_commands(lines[i],&LM,&LW,&FT,&LS) ){			
			if(FT == FMT_OFF){
				cur_pos = 0;
			}
			continue;
		}
		
		/*
		Keep in mind that result[cur_len] could be in the two states before executing
		the conditional statements:
			1. A partially filled one, presumably from formatting.
			2. An empty initialised one.
		*/
		
		/*Process newlines*/
		if (strlen(lines[i]) == 0) {
			/*If this condition runs, then result[cur_len] was in state #1
			otherwise, it is in state #2*/
			if(partial_array){
				cur_len++;
				partial_array = 0;
			}
			result[cur_len] = (char *) malloc (sizeof(char *)); /*One spot for '\0'*/
			*result[cur_len] = '\0';
			cur_len++;
			cur_pos = 0;
			continue;
		}
		
		if (FT == FMT_OFF) {
			/*If this condition runs, then result[cur_len] was in state #1
			otherwise, it is in state #2*/
			if(partial_array){
				cur_len++;
				partial_array = 0;
			}		
			result[cur_len] = (char *) malloc ( (strlen(lines[i])+1)*sizeof(char *) );
			strncpy(result[cur_len],lines[i],(strlen(lines[i])+1));
			cur_len++;
		/*FT on*/
		}else{
			
			/*Create a new block if there isn't already a partial filled result[cur_len]*/
			if (!partial_array) {
				result[cur_len] = (char *) malloc ( (LW+1)*sizeof(char *) );
				cur_pos = 0;
				*result[cur_len] = '\0';
			}
			
			pch = strtok(lines[i]," ");
			/*Append tokens to result from lines[i] string until no more.*/
			while(pch != NULL){
				
				/*Allocate more memory for array of pointers if needed*/
				if (cur_len>=result_max) {
					result_max *= 2;
					result = increase_size(result,result_max);
				}

				/*Add margin if start of new string (presumably after a newline)*/
				if (cur_pos == 0) {
					result[cur_len]=margins(result[cur_len],LM);
					cur_pos+=LM;
				}
				
				/*Append to block if adding a word doesn't exceed block*/
				if (strlen(pch) + cur_pos <= LW ){
					strncat(result[cur_len],pch,strlen(pch)+1);
					strncat(result[cur_len]," ",2);
					cur_pos += strlen(pch) + 1;
				
				
				/*create new block and append token*/
				}else{
					cur_len++; /*update current size of formatted array*/
					//result[cur_len]=spacing(result[cur_len],LS);
					cur_pos = 0; /*reset the line position pointer*/
					result[cur_len] = (char *) malloc((LW+1)*sizeof(char *));
					result[cur_len]=margins(result[cur_len],LM);
					cur_pos += LM;
					//result[cur_len] = '\n';
					strncat(result[cur_len],pch,strlen(pch)+1);
					strncat(result[cur_len]," ",2);
					cur_pos += strlen(pch) + 1;
				}

				pch = strtok(NULL, " ");
				
				
			}/*end while*/
			
				

			partial_array = 1;
		}/*end ifelse for FT on/off*/	
		free(lines[i]); /*free string at slot i in unformatted array*/
	}/*end for*/
	
	if(partial_array==1){
		cur_len++;
	}
	
	free(lines);
	*num_lines = cur_len;
	return result;
	
}/*end format_lines*/

/* METHOD: char ** create_array
 * PARAMETERS: Text file, current size for array, and max size for array
 * RETURN: A new array of string pointers that is unformatted
 * DESCRIPTION: This will dynamically allocate memory for an array of
 * string pointers for the whole text file.
 */
char ** create_array(FILE *infile, int *count){
	char ** ptr;
	int lines_max;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	/*the array of pointers to strings*/
	ptr=(char **) malloc(sizeof(char *));
	if (ptr == NULL) {
		fprintf(stderr, "Error in allocating dynamic memory.\n");
		exit(1);	
	}

	lines_max = 1;
	*count = 0;
	/*For each line, dyn allocate memory for string, then a pointer that is in
	an array of pointers will reference it*/
	while ((read = getline(&line, &len, infile)) != -1 && strncmp(line,"\\0",2)!=0) {
		line[strlen(line)-1] = '\0'; 
		
		/*expand pointer array if needed*/
		if(*count >= lines_max){
		
			lines_max *= 2;
			ptr = increase_size(ptr,lines_max);
		}
		
		ptr[*count] = line;
		line=NULL;
		len=0;
		(*count)++;
	}
	return ptr;
}/*end create_array*/
