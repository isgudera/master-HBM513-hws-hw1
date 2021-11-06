#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printMatrix(&arr, int N){
	for (int m = 0; m < N; m++){
		for (int n = 0; n < N; n++)
		{
			printf("%d",&random[m][n]);
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
	
	int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int B[3][3]={{4,5,7},{2,1,3},{6,0,3}};

	printMatrix(*A,3);

	return 0;
}