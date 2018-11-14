
#include <stdio.h>
#include <stdlib.h>

void printDot(){
	printf(".");
}/* printDot */

void printX(){
	printf("X");
}/* printX */

void printNewline(){
	printf("\n");
}/* printNewline */

int main(void) {
int i,j;
int n=11,m=6,k=1;
for(i=0;i<m;i++){
	for(j=0;j<n-m-i;j++){
		printDot();
	}
	for(j=n-m-i;j<n-m+k;j++){
		printX();
	}
	for(j=n-m+k;j<n;j++){
		printDot();
	}
	printNewline();
	k=k+1;
}

	return EXIT_SUCCESS;
}
