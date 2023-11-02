#include <stdio.h>

void star(int n);

void main()
{
	int n;
	printf("start from : ");
	scanf("%d", &n);
	star(n);
}

void star(int n)
{
	int i;
	if (n > 0) {
		for (i=0; i<n; i++)
			printf("*");
		printf("\n");
		star(n-1);
	}
}
