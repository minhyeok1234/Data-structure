#include <stdio.h>
#include <time.h>

double factorial(int n);

void main()
{
	clock_t start, finish;
	double duration;
	int n;
	double fac;

	printf("input n : ");
	scanf("%d", &n);

	start = clock();
	fac = factorial(n);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%d! = %.2lf\n", n, fac);
	printf("%f seconds\n", duration);
}
double factorial(int n)
{
	if (n==1)
		return 1;
	else
		return n * factorial(n-1);
}
