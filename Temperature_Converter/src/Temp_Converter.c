/*
 ============================================================================
 Name        : Siddharth Pathak
 UVic ID     : V00876495
 Date        : 2016/09/26
 Assignment  : A2
 File Name   : V0876495P1.c
 Description : A program to show temperature in Fahrenheit Degs for different Celsius Degs values.
 ============================================================================
 */
#include<stdio.h>
#include<stdlib.h>

int main(void) {
    const float maxCEL = 100.0;
    const float minCEL = 0.0;
    float CEL = minCEL;
    float FR;
    while (CEL <= maxCEL) {
        FR = ((9*CEL)/5)+32;
        printf("%6.1f degs C = %6.1f degs F\n", CEL, FR);
        CEL=CEL + 10;
    } /*while*/
	return EXIT_SUCCESS;
} /*main*/
