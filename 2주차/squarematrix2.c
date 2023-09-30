#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void matmult(int a[][N], int b[][N], int c[][N]);

int main(void) {
	clock_t start, finish;

