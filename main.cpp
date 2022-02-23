#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Header.h"




int main() {
	srand(time(0));
	int size1[2] = { 0,0 };
	int size2[2] = { 0,0 };
	int printM,num;

	printf("matrix size:\n1)");
	scanf_s("%d:%d", &size1[0], &size1[1]);
	printf("\n2)");
	scanf_s("%d:%d", &size2[0], &size2[1]);
	printf("Max number:");
	scanf_s("%d",&num);
	printf("Print only time?(1/0):");
	scanf_s("%d", &printM);

	TMPtype** matrix1 = createMatrix(size1);
	TMPtype** matrix2 = createMatrix(size2);

	fillMatrix(matrix1, size1,num);
	fillMatrix(matrix2, size2,num);

	int Rsize[2] = { size1[0],size2[1] };
	TMPtype** result = createMatrix(Rsize);

	if (size1[1] != size2[0]) {
		printf("can't multiplie: %d!=%d", size1[1], size2[0]);
		return 0;
	}
	
	double time=checkTime(matrixMultiplie, matrix1, size1, matrix2, size2,result);

	if (!printM) {
		printMatrix(matrix1, size1);
		printf("\n+");
		printMatrix(matrix2, size2);
		printMatrix(result, Rsize);
	}
	
	printf("\ntime:%lf",time);
	delMatrix(matrix1, size1);
	delMatrix(matrix2, size2);
	delMatrix(result, Rsize);

	return 0;
}