/*
Siddharth Pathak
V00876495
Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>

# define SIZE_INT 16

void printBitArray(unsigned char theBits[SIZE_INT]){
	int i;
	for(i = 0;i < SIZE_INT; i++){
		printf("%hu", theBits[i]);
	}
}
unsigned short factorial(unsigned short num){
	if (num == 0){
		return 1;
	}else{
		return(num * factorial(num-1));
	}
}
void toBits(unsigned short value,unsigned char inBits[SIZE_INT]){
	unsigned int mask = 32768;
	int count = 0;
	while(mask > 0){
		if((value & mask)== 0){
			inBits[count]=0;
		}else{
			inBits[count]=1;
		}
		count++;
		// Right Shift
		mask = mask >> 1 ;
   }
}

int main(){
	unsigned short in; 
	unsigned char inBits[SIZE_INT];
	char a;
	int f;
	printf("Input a positive integer: ");
	scanf(" %hu", &in);
	f=factorial(in);
	printf("%hu\tFactorial = %hu or 0b",in,f);
	toBits(f, inBits);
	printBitArray(inBits);
	printf("\nDo you want to continue(Y/N)");
	scanf(" %c",&a);
	while(a=='Y'||a=='y'){
		printf("Input a positive integer: ");
	scanf(" %hu", &in);
	f=factorial(in);
	printf("%hu\tFactorial = %hu or 0b",in,f);
	toBits(f, inBits);
	printBitArray(inBits);
	printf("\nDo you want to continue(Y/N)");
	scanf(" %c",&a);
	}
}
