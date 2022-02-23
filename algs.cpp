#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"


TMPtype** createMatrix(int* size) {
	TMPtype** matrix = (TMPtype**)malloc(sizeof(TMPtype*) * size[0]);
	for (int i = 0; i < size[0]; i++)
		matrix[i] = (TMPtype*)malloc(sizeof(TMPtype) * size[1]);
	return matrix;
}

void fillMatrix(TMPtype** matrix, int* size, int maxsize) {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			matrix[i][j] = rand() % maxsize;
		}
	}

}
void printMatrix(TMPtype** matrix, int* size) {
	printf("\n");
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++)
			printf(" %d ", matrix[i][j]);
		printf("\n");
	}

}
void delMatrix(TMPtype** matrix, int* size) {
	for (int i = 0; i < size[0]; i++)
		free(matrix[i]);
	free(matrix);
}

void matrixMultiplie(TMPtype** matrix1, int* size1, TMPtype** matrix2, int* size2, TMPtype** result) {
	int Rsize[2] = { size1[0],size2[1] };

	for (int i = 0; i < Rsize[0]; i++) {
		for (int j = 0; j < Rsize[1]; j++) {
			result[i][j] = 0;
			for (int k = 0; k < size1[1]; k++)
				result[i][j] += (matrix1[i][k] * matrix2[k][j]);
		}
	}
}
double checkTime(void matrixMultiplie(TMPtype**, int*, TMPtype**, int*, TMPtype**), TMPtype** matrix1, int* size1, TMPtype** matrix2, int* size2, TMPtype** result) {
	double time1 = clock();
	matrixMultiplie(matrix1, size1, matrix2, size2, result);
	double time2 = clock();

	return (time2 - time1) / CLOCKS_PER_SEC;
}
