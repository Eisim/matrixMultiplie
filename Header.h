#pragma once
typedef int TMPtype;


TMPtype** createMatrix(int* size);
void fillMatrix(TMPtype** matrix, int* size, int maxsize);
void printMatrix(TMPtype** matrix, int* size);
void delMatrix(TMPtype** matrix, int* size);
void matrixMultiplie(TMPtype** matrix1, int* size1, TMPtype** matrix2, int* size2, TMPtype** result);
double checkTime(void matrixMultiplie(TMPtype**, int*, TMPtype**, int*, TMPtype**), TMPtype** matrix1, int* size1, TMPtype** matrix2, int* size2, TMPtype** result);