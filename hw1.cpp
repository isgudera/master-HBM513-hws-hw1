#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

/*
int * matrixGenerator(int N) {
	int random[N][N];

	srand((unsigned)time(NULL));
	for (int m = 0; m < N; m++){
		for (int n = 0; n < N; n++)
		{
			random[m][n] = rand()%10;
			printf("%d",random[m][n]);
		}
	}
	return random;
}
 */

double randBtw(double lb, double ub) {
	double range = (ub - lb);
	double div = RAND_MAX / range;
	return (lb + (rand() / div));
}

void fill_2dMatrixRand(double A[SIZE][SIZE] , int row, int col) {
    int i,j;
    double val;
    for(i=0; i<row; i++){
    	for(j=0; j<col; j++){
	    A[i][j] = randBtw(0.0 , 1.0);
	}
    }

}

void printMatrix(double A[SIZE][SIZE], int row,int col) {
	for (int i = 0; i < row; i++){
		for (int j= 0; j < col; j++)
		{
			printf("%6.4lf\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void MatrixMulti_1 (double A[SIZE][SIZE] , double B[SIZE][SIZE], double R[SIZE][SIZE], int row, int col ) {

    for (int k = 0; k < row; k++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < SIZE; i++)
            {   
                R[i][j] = R[i][j] +     A[i][k]*B[k][j];
            }
        }
    }

}

void MatrixMulti_2 (double A[SIZE][SIZE] , double B[SIZE][SIZE], double R[SIZE][SIZE], int row, int col ) {

    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            for (int j = 0; j < SIZE; j++)
            {   
                R[i][j] = R[i][j] +     A[i][k]*B[k][j];
            }
        }
    }

}



//int scenario_0(int);

int main(int argc, char const *argv[])
{
	/*
	int N=3;
	int A;
	A = matrixGenerator(N);
	printf("%d", &A[0][1]);
	*/
	
	double A[SIZE][SIZE], B[SIZE][SIZE], R1[SIZE][SIZE],R2[SIZE][SIZE];
	fill_2dMatrixRand(A,SIZE,SIZE);
	fill_2dMatrixRand(B,SIZE,SIZE);

	struct timespec begin,end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	MatrixMulti_1(A,B,R1,SIZE,SIZE);
	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
	long nanoseconds = end.tv_nsec - begin.tv_nsec;
	double elapsed_time = seconds + nanoseconds*1e-9;

	struct timespec begin2,end2;
	clock_gettime(CLOCK_REALTIME, &begin2);
	
	MatrixMulti_2(A,B,R2,SIZE,SIZE);
	clock_gettime(CLOCK_REALTIME, &end2);
	long seconds2 = end2.tv_sec - begin2.tv_sec;
	long nanoseconds2 = end2.tv_nsec - begin2.tv_nsec;
	double elapsed_time2 = seconds2 + nanoseconds2*1e-9;



	printMatrix(A,SIZE,SIZE);
	printMatrix(B,SIZE,SIZE);
	printMatrix(R1,SIZE,SIZE);
	printMatrix(R2,SIZE,SIZE);
	printf("Elapsed time for multiplication : %.30f seconds. \n" , elapsed_time);
	printf("Elapsed time for multiplication : %.30f seconds. \n" , elapsed_time2);



	return 0;
}
