include <stdio.h>

void star(int n);

int main(void)
{
	int n;
	printf("start from : ");
	scanf("%d", &n);
	star(n);
	return 0;
}

void star(int n)
{
	int i;
	if (n > 0) {
		star(n-1);
		for (i = 0; i < n; i++)
		printf("*");
	}
	printf("\n");
}
