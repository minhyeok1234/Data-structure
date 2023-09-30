#include <stdio.h>
#include <time.h>

double power_recur(double x, int n);

void main()
{
	clock_t start, finish;
	double duration, x, result;
	int n, i;

	printf("Input x : ");
	scanf("%lf", &x);
	printf("Input n : ");
	scanf("%d", &n);

	start = clock();

	result = power_recur(x, n);
	printf("%.2lf^%d = %.2lf\n", x, n, result);

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", duration);
}
double power_recur(double x, int n)
{
	if (n == 0)
		return 1;
	else if((n%2) == 0)
		return power_recur(x * x, n/2);
	else
		return x * power_recur(x * x, (n-1)/2);
}

