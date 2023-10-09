#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rsum (int list[], int n) {
	if(n) {
		return rsum(list, n-1) + list[n-1];
	}
	return 0;
}
void main()
{
	clock_t start, finish;
	double duration;

	int i;
	int* list;
	int length, result;

	printf("The size of list : ");
	scanf("%d", &length);

	list = (int*)malloc(sizeof(int)*length);

	for (i=0; i<length; i++)
		list[i] = i + 1;

	start = clock();
	result = rsum(list, length);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("The total sum(recursion) : %d\n", result);
	printf("%f seconds\n", duration);
}
