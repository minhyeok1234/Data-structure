#include <stdio.h>
#include <stdlib.h>

void input_value(int** m, int row, int col);
void output_value(int** m, int row, int col);

void main()
{
	int row, col;

	printf("input two-demensional array's row : ");
	scanf("%d", &row);
	printf("input two-demensional array's col : ");
	scanf("%d", &col);

	int** d_array = malloc(sizeof(int*)* row);

	for(int i = 0; i < row; i++) {
		d_array[i] = malloc(sizeof(int) * col);
	}
	
	input_value(d_array, row, col);
	output_value(d_array, row, col);

	for(int i = 0; i < row; i++) {
		free(d_array[i]);
	}
	free(d_array);
}
void imput_value(int** m, int row, int col) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			m[i][j] = i + j;
		}
	}
}

void output_value(int** m, int row, int col) {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			printf("%d", m [i][j]);
		}
		printf("\n");
	}
}

