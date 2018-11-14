/*
 ============================================================================
 Name        : Siddharth Pathak
 UvicID      : V00876495
 Date        : 2016/10/24
 Assignment  : A4
 File name   : V00876495A4P1.c
 ============================================================================

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

	int i,num;

	for(i=num;i>0;i++){
	printf("Enter the number between 1 and 4999: ");
	fflush(stdout);
	scanf("%d",&num);
	if(num<1||num>4999){
		printf("Invalid value entered. Program will exit.");
		return 0;
	}
	printf("The value %d in Roman numerals is ",num);
	while(num!=0)
	{
		if(num>=1000){
			for (i=0;i<(num/1000);i++){
				printf("M");}
		    num=num-(num/1000)*1000;
		}
		else if(num>=500){
			if(num<(500+4*100)){
				for(i=0;i<(num/500);i++){
					printf("D");}
				num=num -(num/500)*500;
			}else{
				printf("CM");
				num = num-(1000-100);
			}
		}
		else if(num>=100){
			if(num<(100+3*100)){

				for(i=0;i<(num/100);i++){
					printf("C");}
				num=num-(num/100)*100;}
			else{

				printf("LD");
				num=num-(500-100);
			}
		}
		else if(num>=50){
			if(num<=(50+4*10)){
				for(i=0;i<(num/50);i++)
				{
					printf("L");}
				num=num-(num/50)*50;
			}
			else{

				printf("XC");
				num=num-(num/10)*10;
			}
		}
		else if(num>=10){
				{
					if (num < (10 + 3 * 10))
					            {

					              for(i=0;i<(num/10);i++){
					            	  printf("X");}
					                num = num - (num / 10) * 10;
					            }
					            else
					            {

					                printf("XL");
					                num=num -(50-10);
					            }
					        }
		}
				else if (num>= 5)
				        {
				            if (num<(5 + 4 * 1))
				            {

				                for(i=0;i<(num/5);i++){
				                	printf("V");}
				                num=num-(num/ 5)*5;
				            }
				            else
				            {

				                printf("IX");
				                num=num - (10 - 1);
				            }
				        }
				else if (num>= 1)
				        {
				            if (num< 4)
				            {

				                for(i=0;i<(num/1);i++){
				                printf("I");}
				                num = num - (num / 1) * 1;
				            }
				            else
				            {

				                printf("IV");
				                num = num- (5 - 1);
				            }
				        }
				    }
	printf("\n\n");
	}

	return EXIT_SUCCESS;
	}
