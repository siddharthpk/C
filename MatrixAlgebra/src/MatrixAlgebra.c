/*
 ============================================================================
 Name        : Siddharth Pathak
 UVicID      : V00876495
 Date        : 2016/11/15
 Assignment  : A5
 File name   : V00876495A5P2.c
 Description : This program contains a set of algebra functions for matrix.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* function sqrt() is defined in <math.h> */
#include <stdbool.h>
#include <float.h>
#define BIG_EPSILON  (0.001)


/* ========================================================================= */
/*                              Type Definitions                             */
/*          Do not alter the provided definitions (they will be used         */
/*            for marking). You may add new definitions as needed.           */
/* ========================================================================= */

//Create the Index type
typedef int Index;
//Create the Item type
typedef float Item;

//Define the maximum size of matrix row or column
#define MSIZE     (3)
//Define a Vector type
typedef Item Vector[MSIZE];
//Define a Matrix type
typedef Item Matrix[MSIZE][MSIZE];

/* The constant INVALID_ELEMENT_VALUE contains a value
 * that should never be produced by a valid calculation.
 * In this case, we choose the special floating point value 'NaN'
 * (Not a Number), which is part of the IEEE 754 floating point
 * standard.
 */
const Item INVALID_ELEMENT_VALUE = NAN;

/* ========================================================================= */
/*                       Library Function  Declarations                      */
/*            These functions are defined at the end of the file.            */
/*      The functions are mostly used by the testing code in main(), but     */
/*           you may also find them useful for debugging purposes.           */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */

/* setVector2
   Set the first two elements of the vector V to the provided values (x,y), and set all
   remaining elements to 0.
*/
void setVector2(Vector V, Item x, Item y);

/* setVector3
   Set the first three elements of the vector V to the provided values (x, y, z), and set
   the fourth element to 0.
*/
void setVector3(Vector V, Item x, Item y, Item z);

/* printVector
   Print the first n elements of the vector V to the console.
*/
void printVector(Vector V, Index n);

/* printVectorHightPrecision
   Print the first n elements of the vector V to the console to seven
   decimal places.
*/
void printVectorHighPrecision(Vector V, Index n);

/* matPrint
   Print the provided matrix A to the console.
*/
void matPrint(Matrix A, Index rows, Index cols);

/* equalVectors
   If elements 0, 1, ..., (size-1) of vectors V1 and V2 are equal (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors(Vector V1, Vector V2, Index size, Item eps);

/* equalVectors2
   If the first two elements of V1 are equal to (x, y) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors2(Vector V1, Item x, Item y, Item eps);

/* equalVectors3
   If the first three elements of V1 are equal to (x, y, z) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors3(Vector V1, Item x, Item y, Item z, Item eps);

/* equalMatrix3x3
   If the 3x3 matrix M1 is equal to the matrix described by the nine
   provided values (to within the provided error value eps), return
   true. Otherwise, return false.
*/
bool equalMatrix3x3(Matrix M1, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22, Item eps);

/* matSet3x3
   Set the provided matrix 3x3 matrix A to the values provided.
*/
void matSet3x3(Matrix A, Item a00, Item a01, Item a02, Item a10, Item a11, Item a12, Item a20, Item a21, Item a22);

/* matSetInvalid
   Set every entry of the provided matrix to an invalid value.
*/
void matSetInvalid(Matrix A);

/* ========================================================================= */
/*                           Functions to Implement                          */
/*        Using the types and functions declared above, as well as the       */
/*              Standard Library, implement the functions below.             */
/*              There are a total of 9 functions to implement.               */
/* ========================================================================= */

/* init_matrix_identity
   Set the matrix A to an identity matrix of size (rows x cols).
   An identity matrix contains 1 in every diagonal entry (e.g. A[0][0], A[1][1], etc.)
   and 0 everywhere else.
*/
void init_matrix_identity(Matrix A, Index rows, Index cols) {
	Index k, j;
	for (j=0;  j<rows;  j++){
		for (k=0;  k<cols;  k++){
			if (j == k)
				A[j][k] = 1.0;
			else
				A[j][k] = 0.0;
		}
	}
} /* init_matrix_identity */

/* init_matrix_symmetric
   Set the matrix A to a symmetric matrix where
     A[j][k] = j + k
   for all entries of A within the provided range of rows and columns.
*/
void  init_matrix_symmetric(Matrix A, Index rows, Index cols) {

	/* ... Your code here ... */
	Index j,k;
	for(j=0;j<rows;j++){
		for(k=0;k<cols;k++){
			A[j][k]=j+k;
		}
	}
	printf(">>> init_matrix_symmetric not implemented\n");

} /* init_matrix_symmetric */

/* matrix_copy
   Copy each element of the (rows x cols) matrix SourceMatrix into the provided
   matrix DestMatrix.
*/
void matrix_copy(Matrix SourceMatrix, Matrix DestMatrix, Index rows, Index cols) {

	/* ... Your code here ... */
	Index j,k;
	for(j=0;j<rows;j++){
			for(k=0;k<cols;k++){
				DestMatrix[j][k]=SourceMatrix[j][k];
			}
		}
	printf(">>> matrix_copy not implemented\n");

} /* matrix_copy */

/* matrix_transpose
   Set the provided matrix B to be the transpose of the (rows x cols) matrix
   A. That is, set B[k][j] = A[j][k] for all indices j & k in range.
*/
void matrix_transpose(Matrix A, Matrix B, Index rows, Index cols) {

	/* ... Your code here ... */
	Index j,k;
		for(j=0;j<rows;j++){
				for(k=0;k<cols;k++){
					B[k][j]=A[j][k];
				}
			}
	printf(">>> matrix_transpose not implemented\n");

} /* matrix_transpose */

/* matrix_add_scalar
   Add the scalar value s to every entry of the provided (rows x cols)
   matrix A.
*/
void matrix_add_scalar(Matrix A, Index rows, Index cols, Item s) {

	/* ... Your code here ... */
	Index j,k;
		for(j=0;j<rows;j++){
				for(k=0;k<cols;k++){
					A[j][k]=A[j][k]+s;
				}
			}
	printf(">>> matrix_add_scalar not implemented\n");

} /* matrix_add_scalar */

/* matrix_mul_scalar
   Multiply each entry of the (rows x cols) matrix A by the scalar s.
*/
void matrix_mul_scalar(Matrix A, Index rows, Index cols, Item s) {

	/* ... Your code here ... */
	Index j,k;
			for(j=0;j<rows;j++){
					for(k=0;k<cols;k++){
						A[j][k]=A[j][k]*s;
					}
				}
	printf(">>> matrix_mul_scalar not implemented\n");

} /* matrix_mul_scalar */

/* matrix_add
   Compute the matrix sum C = A + B.
   (i.e. C[k][j] = A[k][j] + B[k][j] for all indices k & j in the provided range)
*/
void matrix_add(Matrix A, Matrix B, Matrix C, Index rows, Index cols) {

	/* ... Your code here ... */
	Index j,k;
			for(j=0;j<rows;j++){
					for(k=0;k<cols;k++){
						C[j][k]=A[j][k]+B[j][k];
					}
				}
	printf(">>> matrix_add not implemented\n");

} /* matrix_add */

/* matrix_multiply
   Compute the product C = A*B using matrix multiplication.

   ARows and ACols contain the number of rows and columns of the matrix A.
   BCols contains the number of columns in B (the number of rows in B is the same
   as the number of columns in A).
*/

void matrix_multiply(Matrix A, Matrix B, int ARows, int ACols, int BCols, Matrix C){

	/* ... Your code here ... */
	/* ... Your code here ... */
		Index j,k,l;
		float sum=0;
				for(j=0;j<ARows;j++){
						for(k=0;k<BCols;k++){
							for(l=0;l<ACols;l++){
								sum=sum+(A[j][l]*B[l][k]);
							}
							C[j][k]=sum;
							sum=0;
						}
					}
	printf(">>> matrix_multiply not implemented\n");

} /* matrix_multiply */

/* matrix_times_vector
   Compute the matrix/vector product A*b and store the result in resultVector.
   The matrix A has dimensions (rows x cols). The vector b has length (cols) and
   the vector resultVector has length (rows).
*/
void matrix_times_vector(Matrix A, Index rows, Index cols, Vector b, Vector resultVector) {

	/* ... Your code here ... */
	Index j,k;
	float sum=0;
				for(j=0;j<rows;j++){
						for(k=0;k<cols;k++){
							sum=sum+(A[j][k]*b[k]);
						}
						resultVector[j]=sum;
						sum=0;
					}

	printf(">>> matrix_times_vector not implemented\n");

} /* matrix_times_vector */


/* ========================================================================= */
/*                               Main Program                                */
/* Contains code to test the 10 functions above. You should add extra tests  */
/*  to ensure that your implemented functions work correctly in all cases.   */
/* ========================================================================= */



/* matrixTest
   A helper function used by main for testing matrix-valued functions.
*/
void matrixTest(char testname[], Matrix Result, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22){
	printf("   Testing %s\n",testname);
	printf("   ==> Expected    %4.1f  %4.1f  %4.1f\n",m00, m01, m02);
	printf("                   %4.1f  %4.1f  %4.1f\n",m10, m11, m12);
	printf("                   %4.1f  %4.1f  %4.1f\n",m20, m21, m22);
	printf("\n");
	printf("   ==> Computed    %4.1f  %4.1f  %4.1f\n",Result[0][0], Result[0][1], Result[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[1][0], Result[1][1], Result[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[2][0], Result[2][1], Result[2][2]);
	if (equalMatrix3x3(Result, m00, m01, m02, m10, m11, m12, m20, m21, m22, BIG_EPSILON)) {
		printf("   ==> Test PASSED\n\n");
	}else{
		printf("ERROR: Test FAILED\n");
		exit(0);
	}
}

/* matrixTest_operator
   A helper function used by main for testing matrix-valued functions.
*/
void matrixTest_operator(char testname[], char operator[], Matrix Operand1, Matrix Operand2, Matrix Result, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22){
	printf("   Testing %s\n",testname);
	printf("   ==> Computing   %4.1f  %4.1f  %4.1f     %4.1f  %4.1f  %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[0][0], Operand2[0][1], Operand2[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f  %s  %4.1f  %4.1f  %4.1f\n",Operand1[1][0], Operand1[1][1], Operand1[1][2],operator,Operand2[1][0], Operand2[1][1], Operand2[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f     %4.1f  %4.1f  %4.1f\n",Operand1[2][0], Operand1[2][1], Operand1[2][2],Operand2[2][0], Operand2[2][1], Operand2[2][2]);
	printf("\n");
	printf("   ==> Expected    %4.1f  %4.1f  %4.1f\n",m00, m01, m02);
	printf("                   %4.1f  %4.1f  %4.1f\n",m10, m11, m12);
	printf("                   %4.1f  %4.1f  %4.1f\n",m20, m21, m22);
	printf("\n");
	printf("   ==> Computed    %4.1f  %4.1f  %4.1f\n",Result[0][0], Result[0][1], Result[0][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[1][0], Result[1][1], Result[1][2]);
	printf("                   %4.1f  %4.1f  %4.1f\n",Result[2][0], Result[2][1], Result[2][2]);
	if (equalMatrix3x3(Result, m00, m01, m02, m10, m11, m12, m20, m21, m22, BIG_EPSILON)) {
		printf("   ==> Test PASSED\n\n");
	}else{
		printf("ERROR: Test FAILED\n");
		exit(0);
	}
}

/* matrixVectorTest
   A helper function used by main for testing vector-valued functions.
*/
void matrixVectorTest(char testname[], char operator[], Matrix Operand1, Vector Operand2, Vector ResultVector, Item x, Item y, Item z){
	printf("   Testing %s\n",testname);
	printf("   ==> Computing   %4.1f  %4.1f  %4.1f     %4.1f\n",Operand1[0][0], Operand1[0][1], Operand1[0][2],Operand2[0]);
	printf("                   %4.1f  %4.1f  %4.1f  %s  %4.1f\n",Operand1[1][0], Operand1[1][1], Operand1[1][2],operator,Operand2[1]);
	printf("                   %4.1f  %4.1f  %4.1f     %4.1f\n",Operand1[2][0], Operand1[2][1], Operand1[2][2],Operand2[2]);
	printf("\n");
	printf("   ==> Expected    %4.1f\n",x);
	printf("                   %4.1f\n",y);
	printf("                   %4.1f\n",z);
	printf("\n");
	printf("   ==> Computed    %4.1f \n",ResultVector[0]);
	printf("                   %4.1f\n",ResultVector[1]);
	printf("                   %4.1f\n",ResultVector[2]);
	if (equalVectors3(ResultVector, x,y,z, BIG_EPSILON)) {
		printf("   ==> Test PASSED\n\n");
	}else{
		printf("ERROR: Test FAILED\n");
		exit(0);
	}
}

int main(void) {
	Matrix M1, M2, M3;
	Matrix Op1, Op2;
	Vector b, x;

	printf("Testing matrix linear algebra functions\n");

	/* Tests for init_matrix_identity */
	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);
	init_matrix_identity(M1, MSIZE, MSIZE);
	matrixTest("init_matrix_identity",M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);

	/* Tests for init_matrix_symmetric */
	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);
	init_matrix_symmetric(M1, 3, 3);
	matrixTest("init_matrix_symmetric (3x3)",M1, 0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);

	matSet3x3(M1, 0,0,0,0,0,0,0,0,0);
	init_matrix_symmetric(M1, 2, 2);
	matrixTest("init_matrix_symmetric (2x2)",M1, 0.0, 1.0, 0.0, 1.0, 2.0, 0.0, 0.0, 0.0, 0.0);


	/* Tests for matrix_copy */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSetInvalid(M2);
	matrix_copy(M1, M2, 3, 3);
	matrixTest("matrix_copy (3x3)",M2, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);

	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSetInvalid(M2);
	matrix_copy(M1, M2, 2, 2);
	matrixTest("matrix_copy (2x2)",M2, 0.0, 1.0, INVALID_ELEMENT_VALUE, 3.0, 4.0, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);

	/* Tests for matrix_transpose */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSetInvalid(M2);
	matrix_transpose(M1, M2, MSIZE, MSIZE);
	matrixTest("matrix_transpose",M2, 0.0, 3.0, 6.0, 1.0, 4.0, 7.0, 2.0, 5.0, 8.0);


	/* Tests for matrix_add_scalar */
	matSet3x3(M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
	matrix_add_scalar(M1, 3, 3, 0.2);
	matrixTest("matrix_add_scalar (3x3)",M1, 1.2, 0.2, 0.2, 0.2, 1.2, 0.2, 0.2, 0.2, 1.2);

	matSet3x3(M1, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
	matrix_add_scalar(M1, 2, 2, 0.2);
	matrixTest("matrix_add_scalar (2x2)",M1, 1.2, 0.2, 0.0, 0.2, 1.2, 0.0, 0.0, 0.0, 1.0);

	/* Tests for matrix_mul_scalar */
	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matrix_mul_scalar(M1, 3, 3, 2.0);
	matrixTest("matrix_mul_scalar (3x3)",M1, 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);

	matSet3x3(M1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matrix_mul_scalar(M1, 2, 3, 2.0);
	matrixTest("matrix_mul_scalar (2x3)",M1, 0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 6.0, 7.0, 8.0);

	/* Tests for matrix_add */
	matSet3x3(M1,  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(Op1, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(M2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSetInvalid(M3);
	matrix_add(M1, M2, M3, 3, 3);
	matrixTest_operator("matrix_add (3x3 - Test 1)","+",Op1, Op2, M3, 0.0, 2.0, 4.0, 4.0, 6.0, 8.0, 8.0, 10.0, 12.0);

	matSet3x3(M1,  1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
	matSet3x3(Op1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
	matSet3x3(M2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSetInvalid(M3);
	matrix_add(M1, M2, M3, 3, 3);
	matrixTest_operator("matrix_add (3x3 - Test 2)","+",Op1, Op2, M3, 1.1, 3.2, 5.3, 5.4, 7.5, 9.6, 9.7, 11.8, 13.9);

	matSet3x3(M1,  1.1, 2.2, 3.3, 4.4, 5.5, 6.6, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(M2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op2,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSetInvalid(M3);
	matrix_add(M1, M2, M3, 2, 3);
	matrixTest_operator("matrix_add (2x3)","+",Op1, Op2, M3, 1.1, 3.2, 5.3, 5.4, 7.5, 9.6, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);

	matSet3x3(M1,  1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, 7.7, 8.8, INVALID_ELEMENT_VALUE);
	matSet3x3(Op1, 1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, 7.7, 8.8, INVALID_ELEMENT_VALUE);
	matSet3x3(M2,  0.0, 1.0, INVALID_ELEMENT_VALUE, 1.0, 2.0, INVALID_ELEMENT_VALUE, 2.0, 3.0, INVALID_ELEMENT_VALUE);
	matSet3x3(Op2,  0.0, 1.0, INVALID_ELEMENT_VALUE, 1.0, 2.0, INVALID_ELEMENT_VALUE, 2.0, 3.0, INVALID_ELEMENT_VALUE);
	matSetInvalid(M3);
	matrix_add(M1, M2, M3, 3, 2);
	matrixTest_operator("matrix_add (3x2)","+",Op1, Op2, M3, 1.1, 3.2, INVALID_ELEMENT_VALUE, 5.4, 7.5, INVALID_ELEMENT_VALUE, 9.7, 11.8, INVALID_ELEMENT_VALUE);

	/* Tests for matrix_multiply */
	matSet3x3(M1,  0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op1, 0.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(M2,  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSet3x3(Op2, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
	matSetInvalid(M3);
	matrix_multiply(M1,M2, 3, 3,3, M3);
	matrixTest_operator("matrix_multiply (3x3 - Test 1)","*",Op1, Op2, M3, 15.0, 18.0, 21.0, 24.0, 30.0, 36.0, 33.0, 42.0, 51.0);

	matSet3x3(M1,  1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
	matSet3x3(Op1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9);
	matSet3x3(M2,  1.0, 2.0, 3.0, 4.9, 5.8, 6.7, 7.0, 8.0, 9.0);
	matSet3x3(Op2, 1.0, 2.0, 3.0, 4.9, 5.8, 6.7, 7.0, 8.0, 9.0);
	matSetInvalid(M3);
	matrix_multiply(M1,M2, 3,3,3, M3);
	matrixTest_operator("matrix_multiply (3x3 - Test 2)","*",Op1, Op2, M3, 34.98, 41.36, 47.74, 77.55, 93.5, 109.45, 120.12, 145.64, 171.16);

	matSet3x3(M1,  1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op1, 1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(M2,  1.0, 2.0, INVALID_ELEMENT_VALUE, 4.9, 5.8, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op2, 1.0, 2.0, INVALID_ELEMENT_VALUE, 4.9, 5.8, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSetInvalid(M3);
	matrix_multiply(M1,M2, 2,2,2, M3);
	matrixTest_operator("matrix_multiply (2x2)","*",Op1, Op2, M3, 11.88, 14.96, INVALID_ELEMENT_VALUE, 31.35, 40.7, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);

	matSet3x3(M1,  1.1, 2.2, 3.3, 4.4, 5.5, 6.6, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op1, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(M2,  1.0, 2.0, INVALID_ELEMENT_VALUE, 4.9, 5.8, INVALID_ELEMENT_VALUE, 7.0, 8.0, INVALID_ELEMENT_VALUE);
	matSet3x3(Op2, 1.0, 2.0, INVALID_ELEMENT_VALUE, 4.9, 5.8, INVALID_ELEMENT_VALUE, 7.0, 8.0, INVALID_ELEMENT_VALUE);
	matSetInvalid(M3);
	matrix_multiply(M1,M2, 2, 3,2, M3);
	matrixTest_operator("matrix_multiply (2x3 times 3x2)","*",Op1, Op2, M3, 34.98, 41.36, INVALID_ELEMENT_VALUE, 77.55, 93.5, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);

	matSet3x3(M1,  1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, 7.7, 8.8, INVALID_ELEMENT_VALUE);
	matSet3x3(Op1, 1.1, 2.2, INVALID_ELEMENT_VALUE, 4.4, 5.5, INVALID_ELEMENT_VALUE, 7.7, 8.8, INVALID_ELEMENT_VALUE);
	matSet3x3(M2,  1.0, 2.0, 3.0, 4.9, 5.8, 6.7, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSet3x3(Op2, 1.0, 2.0, 3.0, 4.9, 5.8, 6.7, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE, INVALID_ELEMENT_VALUE);
	matSetInvalid(M3);
	matrix_multiply(M1,M2, 3, 2, 3, M3);
	matrixTest_operator("matrix_multiply (3x2 times 2x3)","*",Op1, Op2, M3, 11.88, 14.96, 18.04, 31.35, 40.7, 50.05, 50.82, 66.44, 82.06);


	/* Tests for matrix_times_vector */
	matSet3x3(M1,  5.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	matSet3x3(Op1, 5.0, 1.0, 2.0, 1.0, 2.0, 3.0, 2.0, 3.0, 4.0);
	setVector3(b, 1,2,3);
	matrix_times_vector(M1, 3, 3, b, x);
	setVector3(b, 1,2,3);
	matrixVectorTest("matrix_times_vector (Test 1)", "*", Op1, b, x, 13, 14, 20);


	matSet3x3(M1,  5.9, 1.8, 2.7, 1.1, 2.2, 3.3, 2.3, 3.4, 4.5);
	matSet3x3(Op1, 5.9, 1.8, 2.7, 1.1, 2.2, 3.3, 2.3, 3.4, 4.5);
	setVector3(b,  1.5 ,2.5 ,3.5);
	matrix_times_vector(M1, 3, 3, b, x);
	setVector3(b,  1.5 ,2.5 ,3.5);
	matrixVectorTest("matrix_times_vector (Test 2)", "*", Op1, b, x, 22.8, 18.7, 27.7);

	printf("All tests passed!\n");
	return EXIT_SUCCESS;
} /* main */


/* ========================================================================= */
/*                           Library Functions                               */
/*         These are declared above, and are used for testing the            */
/*        linear algebra functions. Do not modify these functions.           */
/* ========================================================================= */

/* setVector2
   Set the first two elements of the vector V to the provided values (x,y), and set all
   remaining elements to 0.
*/
void setVector2(Vector V, Item x, Item y) {
	/* V = {x, y} */
	V[0] = x; V[1] = y;	V[2] = 0.0;
} /* setVector2 */

/* setVector3
   Set the three elements of the vector V to the provided values (x, y, z).
*/
void setVector3(Vector V, Item x, Item y, Item z) {
	/* V = {x, y, z} */
	V[0] = x; V[1] = y; V[2] = z;
} /* setVector3 */

/* printVector
   Print the first n elements of the vector V to the console.
*/
void printVector(Vector V, Index n){
	/* output V[0], V[1], V[2], ..., V[n-1] */
	Index k;
	printf("   ");
	for (k=0; k < n; k++)
		printf("%.1f  ", V[k]);
	printf("\n");
} /* printVector */

/* printVectorHightPrecision
   Print the first n elements of the vector V to the console to seven
   decimal places.
*/
void printVectorHighPrecision(Vector V, Index n) {
	/* output V[0], V[1], V[2], ..., V[n-1] */
	Index k;
	printf("   ");
	for (k=0; k < n; k++)
		printf("%.7f  ", V[k]);
	printf("\n");
} /* printVectorHighPrecision */

/* matPrint
   Print the provided matrix A to the console.
*/
void matPrint(Matrix A, Index rows, Index cols) {
	/* output V[0][0], V[0][1], V[0][2], ..., V[0][cols-1] */
	/* output V[1][0], V[1][1], V[1][2], ..., V[1][cols-1] */
	/* ... */
	/* output V[rows-1][0], V[rows-1][1], V[rows-1][2], ..., V[rows-1][cols-1] */
	Index k, j;
	for (j=0;  j<rows;  j++) {
		for (k=0;  k<cols;  k++)
			printf("   %.1f", A[j][k]);
		printf("   \n");
	} /* for */
	printf("\n");
} /* matPrint */


/* equalVectors
   If elements 0, 1, ..., (size-1) of vectors V1 and V2 are equal (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors(Vector V1, Vector V2, Index size, Item eps) {
	/* return true if V1 == V2; false otherwise */
	Index k;
	for (k=0; k<size; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			// Vectors are not equal
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors */

/* equalVectors2
   If the first two elements of V1 are equal to (x, y) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors2(Vector V1, Item x, Item y, Item eps) {
	/* return true if V1 == {x, y}; false otherwise */
	Index k;
	Vector V2 = {x, y};
	for (k=0; k<2; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors2 */

/* equalVectors3
   If the first three elements of V1 are equal to (x, y, z) (to within
   the provided error value eps), return true. Otherwise, return false.
*/
bool equalVectors3(Vector V1, Item x, Item y, Item z, Item eps) {
	/* return true if V1 == {x, y, z}; false otherwise */
	Index k;
	Vector V2 = {x, y, z};
	for (k=0; k<3; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors3 */

/* equalMatrix3x3
   If the 3x3 matrix M1 is equal to the matrix described by the nine
   provided values (to within the provided error value eps), return
   true. Otherwise, return false.
*/
bool equalMatrix3x3(Matrix M1, Item m00, Item m01, Item m02, Item m10, Item m11, Item m12, Item m20, Item m21, Item m22, Item eps) {
	Matrix M2 = {{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}};
	Index k, j;
	for (j = 0;  j < 3;  j++) {
		for (k = 0;  k < 3;  k++){
			if (isnan(M1[j][k]) || isnan(M2[j][k])){
				if(!isnan(M1[j][k]) || !isnan(M2[j][k]))
					return false;
			}else if (fabs(M1[j][k]-M2[j][k]) > eps && !(isnan(M1[j][k]) && isnan(M2[j][k]))) {
				return false;
			} /* if */
		}
	} /* for */
	return true;
} /* equalMatrix3x3 */

/* matSet3x3
   Set the provided matrix 3x3 matrix A to the values provided.
*/
void matSet3x3(Matrix A, Item a00, Item a01, Item a02, Item a10, Item a11, Item a12, Item a20, Item a21, Item a22) {
	/* init 3x3 matrix */
	A[0][0] = a00;  A[0][1] = a01;  A[0][2] = a02;
	A[1][0] = a10;  A[1][1] = a11;  A[1][2] = a12;
	A[2][0] = a20;  A[2][1] = a21;  A[2][2] = a22;
} /* matSet3x3 */


/* matSetInvalid
   Set every entry of the provided matrix to an invalid value.
*/
void matSetInvalid(Matrix A) {
	Index k, j;
	for (j=0;  j < MSIZE;  j++) {
		for (k=0;  k < MSIZE;  k++){
			A[j][k] = INVALID_ELEMENT_VALUE;
		} /* for */
	} /* for */
} /* matSetInvalid */
