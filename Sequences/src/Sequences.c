/*
 ============================================================================
 Name        : Siddharth Pathak
 UVic ID     : V00876495
 Date        : 2016/09/26
 Assignment  : A2
 File Name   : V0876495P2.c
 Description : A program to print Arithmetic, Harmonic and Leonardo Sequence.
 ============================================================================
 */

/* ArithmeticSequence(start, increment, count)

   Print an arithmetic sequence with the provided properties:
    - start: first value in the sequence
    - increment: the increment value between each pair of values in the sequence
    - count: number of terms to generate

*/
void ArithmeticSequence(int start, int increment, int count){
int j=0;
printf("Arithmetic Sequence: ");
while(j<count){
int i;
i=start;
printf("%d   ",i);
start=start+increment;
j++;

}
printf("\n");

}

/* HarmonicSequence()

   Print the first 10 entries of the harmonic sequence.

*/
void HarmonicSequence(){
	float start=1;
	float increment=1;
	int j=0;
	float z;
	float k;
	printf("Harmonic Sequence: ");
	while(j<10){
		z=start;
		printf("%.2f\t",z);
		k=1+increment;
		start=1/k;
		j++;
		increment++;
     }
   printf("\n");

}

/* LeonardoSequence()

   Print the first 10 entries of the Leonardo sequence.

*/
void LeonardoSequence(){
    printf("Leonardo Sequence: ");
    int i=0;
	int start=1;
	int prev=1;
	int next=1;
	while(i<10){
	 	printf("%d  ",start);
		next=start+prev+1;
		start=prev;
		prev=next;
		i++;


	}
}

/* Do not change any code below this line */
int main(){
	ArithmeticSequence(17, 6, 5);
	ArithmeticSequence(10, 6, 10);
	HarmonicSequence();
	LeonardoSequence();
	return 0;
}
