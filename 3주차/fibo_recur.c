#include <stdio.h>
#include <time.h>

int fib(int n);

void main()
{
	clock_t start, finish;
	double duration;
	int n, i, result;

	printf("Input n : ");
	scanf("%d", &n);

	start = clock();

	result = fib(n);
	printf("fib(%d) = %d\n", n, result);

	finish = clock();

	duration = (double)(finish - strat) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
}
int fib(int n)
{
	if (n == 0)
		return 0;
	if (n ==1)
		return 1;
	else
		return (fib(n-1) + fib(n-2));
}
