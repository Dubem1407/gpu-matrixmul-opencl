/**
* Matrix Multiplication: C = A * B
* CPU implementation code
*/

//system include
#include <stdio.h>
#include <stdlib.h>

//use program timer
#include <sys/time.h>
#include <time.h>
//define constant: matrix size
#define DEFAULT_SIZE 4
// #define DEBUG

void matrixMultiple(float matrixa[], float matrixb[], float matrixc[], int ROW1, int COL1, int ROW2, int COL2)
{
	// fill in code for matrix multiplication

	for (int i = 0; i < ROW1; i++) {
		for (int j = 0; j < COL2; j++) {
			matrixc[i * COL2 + j] = 0;

			for (int k = 0; k < ROW2; k++){
				matrixc[i * COL2 + j] += matrixa[i * COL1 + k] * matrixb[k * COL2 + j];
			}
		}
	}
		

}

int main(int argc, char** argv)
{

	int MSIZE = DEFAULT_SIZE;
    if (argc > 1) {
        MSIZE = atoi(argv[1]);
    }

    int ROW1 = MSIZE;
    int COL1 = MSIZE;
    int ROW2 = MSIZE;
    int COL2 = MSIZE;
	
	float *matrixA = (float*)malloc(sizeof(float) * ROW1 * COL1);
    float *matrixB = (float*)malloc(sizeof(float) * ROW2 * COL2);
    float *matrixC = (float*)malloc(sizeof(float) * ROW1 * COL2);

    if (!matrixA || !matrixB || !matrixC) {
        printf("Memory allocation failed.\n");
        return 1;
    }

	int i;
	
	//define variables to use timer
	//clock_t start, finish;
	//float duration;
	struct timeval begin, end;
	int t_usec;
	int t_sec;
	int t_sec_final;
	int t_usec_final;

	//initialize matrix A and matrix B
	//put in random values
#ifndef DEBUG
	int seed;
	seed = time(NULL);
	srand(seed);
#endif
	for(i = 0; i < ROW1 * COL1; i++)
	{
#ifdef DEBUG
		matrixA[i] = rand() % 2000;
#else
		matrixA[i] = rand();
#endif
	}
	for(i = 0; i < ROW2 * COL2; i++)
	{
#ifdef DEBUG
		matrixB[i] = rand() % 2000;
#else
		matrixB[i] = rand();
#endif
	}

	//record start time
	//start = clock();

	gettimeofday(&begin, NULL);

	matrixMultiple(matrixA, matrixB, matrixC, ROW1, COL1, ROW2, COL2);

	//record finish time
	//finish = clock();
	gettimeofday(&end, NULL);
	
	//calculate time needed to do matrix multiplication
	//duration = (double)(finish - start);
	t_usec = end.tv_usec - begin.tv_usec;
	t_sec = end.tv_sec - begin.tv_sec;
	if(t_usec >= 0)
	{
		t_sec_final = t_sec;
		t_usec_final = t_usec;
	}
	else
	{
		t_sec_final = t_sec - 1;
		t_usec_final = 999999 + t_usec;
	}

#ifdef DEBUG
	// output matrix
	printf("matrixA =");
	for(i = 0; i < ROW1 * COL1; i++)
	{
		if(i % COL1 == 0)
		{
			printf("\n");
		}
		printf("%.0f\t", matrixA[i]);
	}
	printf("\n\n");
	printf("matrixB =\n");
	for(i = 0; i < ROW2 * COL2; i++)
	{
		if(i % COL2 == 0)
		{
			printf("\n");
		}
		printf("%.0f\t", matrixB[i]);
	}
	printf("\n\n");
	printf("matrixC=\n");
	for(i = 0; i < ROW1 * COL2; i++)
	{
		if(i % COL2 == 0)
		{
			printf("\n");
		}
		printf("%.0f\t", matrixC[i]);
	}
	printf("\n\n");
#endif

	//output the matrix dimension and 
	//elapsed time when doing multiplication
	printf("Dimension of matrixA: %d x %d\n", ROW1, COL1);
	printf("Dimension of matrixB: %d x %d\n", ROW2, COL2);
	printf("CPU matrix multiplication time: %d%03d.%03d ms\n",
           t_sec_final, t_usec_final / 1000, t_usec_final % 1000);
	
	free(matrixA);
    free(matrixB);
    free(matrixC);

	return 0;
}
