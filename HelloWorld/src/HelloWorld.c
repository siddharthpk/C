/*
 ============================================================================
 Name        : V00876495P2A4i.c
 Author      : Siddharth Pathak
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int p(int a){
	a=a*3;
	printf("%d",a);
	return p1(a);
}

int p1(int b){
	b=b*5;
	printf("%d\n",b);
	return b;
}

int main(void){

	int z;
	z=p(15);
	printf("%d",z);

	return EXIT_SUCCESS;
} /*main*/
