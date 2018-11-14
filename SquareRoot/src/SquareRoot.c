/*
 ============================================================================
 Name        : Siddharth Pathak
 UVicID      : V00876495
 Date        : 2016/09/22
 Assignment  : A2
 File Name   : V00876495P3.c
 Description : A program to approximate value of square root of 111.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double x=1.0;
	double x_new;
	int rep_count=10;
	int i=0;
	float T=111;
	while(rep_count>0)
	{
		printf("Before step %d",i);
	printf(": %14.10f\n",x);
	    x_new=x-(((x*x)-T)/(2*x));
	    x=x_new;
        rep_count--;
        i=i+1;
	}
	printf("Final approximation: %14.10f",x);

	return EXIT_SUCCESS;
}
