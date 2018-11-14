
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float coneVol(float r,float h){
	float vol=M_PI*(1.0/3.0)*r*r*h;
	return vol;
}

int main(void) {
	int i,j;
	float b=1.0;
	printf("h\tr = 1\tr = 2\tr = 3\tr = 4\tr = 5\tr = 6\tr = 7\tr = 8\tr = 9\n");
for(i=1;i<=10;i++){
	float a=1.0;
	printf("%d\t",i);
for(j=1;j<=9;j++){
	float k=coneVol(a,b);
	printf("%.2f\t",k);
	a=a+1;
	}
b=b+1;
printf("\n");
}

	return EXIT_SUCCESS;
}
