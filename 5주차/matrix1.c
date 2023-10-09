#include <stdio.h>
#include <stdlib.h>

int ROWS = 3, COLS = 3;

void input(int** array) {
	int i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			scanf("%d", &array[i][j]);
}

void sparse_matrix_add1(int** A, int** B, int** C) {
	int i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			C[i][j] = A[i][j] + B[i][j];
}

void main()
{
	int i, j;
	int** array1 = malloc(sizeof(int* ) * ROWS);
	int** array2 = malloc(sizeof(int* ) * ROWS);
	int** array3 = malloc(sizeof(int* ) * ROWS);

	for (i=0; i<ROWS; i++) {
		array1[i] = malloc(sizeof(int) * COLS);
		array2[i] = malloc(sizeof(int) * COLS);
		array3[i] = malloc(sizeof(int) * COLS);
	}

	printf("input array1:\n");
	input(array1);
	printf("input array2:\n");
	input(array2);

	sparse_matrix_add1(array1, array2, array3);

	printf("array3:\n");
	for (i=0; i<ROWS; i++)
		for (j=0; j<COLS; j++) {
			printf("%d", array3[i][j]);
			if (j == 2) printf("\n");
		}
	for (i=0; i<ROWS; i++) {
		free(array1[i]);
		free(array2[i]);
		free(array3[i]);
	}
	free(array1);
	free(array2);
	free(array3);
}
