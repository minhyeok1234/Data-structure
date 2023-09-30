#include <stdio.h>
#include <time.h>

double power_iter(double x, int n);

void main()  {
	clock_t start, finish;
	double duration, x, result;
	int n, i;

	printf("Input x : ");
	scanf("%lf", &x);

	printf("Input n : ");
	scanf("%d", &n);

	start = clock();

	result = power_iter(x, n);
	printf("%.2lf^%d = %.2lf\n", x, n, result);

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f, seconds\n", duration);
}

double power_ier(double x, int n)
{
	int i;
	double r = 1.0;

	for(i = 0; i < n; i++)
		r = r * x;

	return r;
}

